#include "Getname.C"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
#include "gethisto.C"
#include "ISR.C"

gSystem->Load("libRooFit");
using namespace std;
using namespace RooFit;


void CROSS() {
	gStyle->SetOptTitle(0);
	/// variables
	double threepiIM = 0.;
	double pi0IMreso = Resolu[1];
	double threepiIMreso = Resolu[0];
	double subrange1 = 720., subrange2 = 820.;
	RooRealVar x("ThreepiIM","ThreepiIM",xmin_IM,xmax_IM);
	RooRealVar y("IMthreepi_MC","IMthreepi_MC",xmin_IM,xmax_IM);
	const Int_t binnb = 100;
	/// get root files
	TFile *findFile = new TFile("./ROOT/TREE_cutted.root","READ");
	TFile *findFile1 = new TFile("./ROOT/TREE_Gen.root","READ");
	x.setBins(binnb); y.setBins(binnb);
	double binwidth_temp = (xmax_IM-xmin_IM)/binnb;
	std::cout<<"BIN WIDTH = "<<binwidth_temp<<" MeV"<<endl;
	x.setBins(100000,"fft");
	
	/// get trees 
	// tree names
	TString Omegpi = gettreename(0);// omega pi0
	TString Ksl = gettreename(2);// KSL
	TString Omegam = gettreename(3);// omega gamma
	TString MCrest = gettreename(7);// mc rest = bkgsum2
	TString Data = gettreename(10);// data
	// find trees
	TTree *TData = (TTree*)findFile->Get("T"+Data+"_Pre"); // data
	TTree *TKsl = (TTree*)findFile->Get("T"+Ksl+"_Pre"); // ksl
	TTree *TOmegpi = (TTree*)findFile->Get("T"+Omegpi+"_Pre");// omegapi
	TTree *TOmegam = (TTree*)findFile->Get("T"+Omegam+"_Pre"); // omega gamma
	TTree *TMCrest = (TTree*)findFile->Get("T"+MCrest+"_Pre"); // MCrest
	TTree *TOmegam_Gen = (TTree*)findFile1->Get("T"+Omegam+"_MC"); // omega gamma MC true	
	// branch names
	TString SIMthreepi = getbraname(1);
	TString SThreepiIM = getbraname(9);
	// filling tree with branches (Reconstr.)
	// tree list
	TCollection* treelist = new TList;
	treelist->Add(TData);
	treelist->Add(TKsl);
	treelist->Add(TOmegpi);
	treelist->Add(TOmegam);
	treelist->Add(TMCrest);
	
	TObject* treeout=0;
	TIter treeliter(treelist);
	while((treeout=treeliter.Next()) !=0) {
		//treeout->Print();
		TTree* tree_temp=dynamic_cast<TTree*>(treeout);
		tree_temp->SetBranchAddress(SThreepiIM,&threepiIM);
	}
	// filling tree with branches (Generated)
	TOmegam_Gen->SetBranchAddress(SIMthreepi+"_MC",&threepiIM);
	
	/// Detector response function
   RooRealVar mg("mg","mg",1.,0.,3.);
   RooRealVar sg("sg","sg",pi0IMreso,0.,10.);
	RooGaussian gauss("gauss","gauss",x,mg,sg);
	
	RooRealVar mg1("mg1","mg1",782.65);
   RooRealVar sg1("sg1","sg1",pi0IMreso,0.,10.);
	RooGaussian gauss1("gauss1","gauss1",x,mg1,sg1);
	
	/// get histo. pdfs
	// data	
	double N_d=0;
	TH1D* HData = new TH1D("HData","data",binnb,xmin_IM,xmax_IM); HData->Sumw2();
	for (Int_t irow=0;irow<TData->GetEntries();irow++) {
		TData->GetEntry(irow); 
		HData->Fill(threepiIM); 
		N_d++;
   }
   std::cout<<"N_d = "<<N_d<<endl;
   // data set
   RooDataSet data("data","data",RooArgSet(x),Import(*TData));
   
   // ksl
   double N_ksl=0, fksl_init=0;
   for (Int_t irow=0;irow<TKsl->GetEntries();irow++) {
   	TKsl->GetEntry(irow); 
   	N_ksl++;
   }
   fksl_init=N_ksl/N_d; 
   std::cout<<"N_ksl = "<<N_ksl<<", fksl_init = "<<fksl_init<<endl;
   
   RooDataSet ksl("ksl","ksl",TKsl,x);
   RooKeysPdf kslpdf("kslpdf", "kslpdf", x, ksl, RooKeysPdf::MirrorBoth, 1);
   
   // omegpi 
   double N_omegpi=0, fomegpi_init=0;
   for (Int_t irow=0;irow<TOmegpi->GetEntries();irow++) {
   	TOmegpi->GetEntry(irow); 
   	N_omegpi++;
   }
   fomegpi_init=N_omegpi/N_d;
   std::cout<<"N_omegpi = "<<N_omegpi<<", fomegpi_init = "<<fomegpi_init<<endl;
   
   RooDataSet omegpi("omegpi","omegpi",TOmegpi,x);
   RooKeysPdf omegpipdf("omegpipdf", "omegpipdf", x, omegpi, RooKeysPdf::MirrorBoth, 1);
   
   // omegam
   double N_omegam=0, fomegam_init=0;
   TH1D* HOmegam = new TH1D("HOmegam","generated omegam",binnb,xmin_IM,xmax_IM); HOmegam->Sumw2();
   for (Int_t irow=0;irow<TOmegam->GetEntries();irow++) {
   	TOmegam->GetEntry(irow); 
   	HOmegam->Fill(threepiIM);
   	N_omegam++;	
   }
   fomegam_init=N_omegam/N_d; 
   std::cout<<"N_omegam = "<<N_omegam<<", fomegam_init = "<<fomegam_init<<endl;
   
   RooDataSet omegam("omegam","omegam",TOmegam,x);
   RooKeysPdf omegampdf("omegampdf", "omegampdf", x, omegam, RooKeysPdf::MirrorBoth, 1);
   
   // Construct convolution
	RooFFTConvPdf omegampdfcov("omegampdfcov","omegam (X) gauss",x,omegampdf,gauss);
   
   // omegam generated
   double N_omegam_gen = 0;
   TH1D* HOmegam_gen = new TH1D("HOmegam_gen","generated omegam",binnb,xmin_IM,xmax_IM); HOmegam_gen->Sumw2();
   for (Int_t irow=0;irow<TOmegam_Gen->GetEntries();irow++) { 
   	TOmegam_Gen->GetEntry(irow);
   	HOmegam_gen->Fill(threepiIM);
   	N_omegam_gen++;
   	//cout<<threepiIM<<endl;
   }
   std::cout<<"N_omegam_gen = "<<N_omegam_gen<<endl;
   
   // mc rest   
   double N_mcrest=0, fmcrest_init=0;
   for (Int_t irow=0;irow<TMCrest->GetEntries();irow++) {
   	TMCrest->GetEntry(irow); 
   	N_mcrest++;
   } 
   fmcrest_init=N_mcrest/N_d;
   std::cout<<"N_mcrest = "<<N_mcrest<<", fmcrest_init = "<<fmcrest_init<<endl;
   
   RooDataSet mcrest("mcrest","mcrest",TMCrest,x);
   RooKeysPdf mcrestpdf("mcrestpdf", "mcrestpdf", x, mcrest, RooKeysPdf::MirrorBoth, 1);
   
   // threepi gamma
   double fthreepigam_init = 0;
   RooRealVar a0("a0","coefficient #0", -0.1,-10.,10.); 
	RooRealVar a1("a1","coefficient #1", -0.1,-10.,10.); 
	RooRealVar a2("a2","coefficient #2", -0.1,-10.,10.); 
	RooChebychev threepigampdf("threepigampdf","threepigampdf",x,RooArgList(a0,a1,a2));
	
   /*RooRealVar a0("a0","a0",0.5,-10.,10.) ;
   RooRealVar a1("a1","a1",-0.2,-10.,10.) ;
   RooChebychev threepigampdf("threepigampdf","threepigampdf",x,RooArgSet(a0,a1));*/
   
   fthreepigam_init=1-fomegpi_init-fksl_init-fomegam_init-fmcrest_init;
   std::cout<<"fthreepigam_init = "<<fthreepigam_init<<endl;
   
   // constrcut model for fit in control region [xmin fitcut]
   // variable
   RooRealVar fthreepigam("fthreepigam","threepigam fraction",fthreepigam_init);
   RooRealVar fmcrest("fmcrest","mcrest fraction",fmcrest_init);
   RooRealVar fksl("fksl","ksl fraction",fksl_init);
   RooRealVar fomegpi("fomegpi","omegpi fraction",fomegpi_init); 
   RooRealVar sigfrac("sigfrac","signal fraction",fomegam_init);
   
   RooRealVar nsig("nsig","signal fraction",10000,0.,100000.) ;
	RooRealVar nbkgsum("nbkgsum","background fraction",10000,0.,100000.) ;
   // models
   RooAddPdf sig("sig","Signal",omegampdfcov,sigfrac);
	RooAddPdf bkgsum("bkgsum","bkgsum",RooArgList(omegpipdf,kslpdf,mcrestpdf,threepigampdf,threepigampdf),RooArgList(fomegpi,fksl,fmcrest,fthreepigam));
	//RooAddPdf bkgsum("bkgsum","bkgsum",threepigampdf,fthreepigam);
	RooAddPdf model("model","model",RooArgList(sig,bkgsum),RooArgList(nsig,nbkgsum));
	// fit
   RooFitResult* rf = model.fitTo(data,Extended(),Save());
   RooArgSet* params = model.getVariables();
   //params->Print("v");
   double Nbsig = 0., err_Nbsig  = 0.;
   double Nbbkgsum = 0., err_Nbbkgsum = 0.;
   double effic_bin = 0., err_effic_bin = 0.;
   
   Nbsig = nsig.getVal(); // get expected omegam events number
   err_Nbsig = nsig.getError(); // get error of Nbsig 
   
   Nbbkgsum = nbkgsum.getVal(); // get expected bkgsum events number
   err_Nbbkgsum = nbkgsum.getError(); // get error of Nbbkg 
   
   std::cout<<"NBSIG = "<<Nbsig <<"+/-"<<err_Nbsig<<endl;
   std::cout<<"NBBKGSUM = "<<Nbbkgsum <<"+/-"<<err_Nbbkgsum<<endl;
   
   /// check histos
   // create histo for differential cross section of omega gamma
   TH1D* HDiffCross = new TH1D("HDiffCross","differential cross section of omega gamma",binnb,xmin_IM,xmax_IM); HDiffCross->Sumw2();
   TH1D* HCross = new TH1D("HCross","cross section of omega gamma",binnb,xmin_IM,xmax_IM); HCross->Sumw2();
   TAxis* axis_hhdata = HData->GetXaxis();
   double binsize = 0.;
   double nbdata = 0., errdata = 0., mvalue = 0.;
   double Nsig_gen = 0., Nsig_rec = 0., efficy = 0.;
   double efficy_list[binnb], isr_list[binnb], m_list[binnb];
   double Nsig_sel = 0., Nbkg_sel = 0., fbkg = 0.;
   double err_nbkg_sel = 0., err_fbkg = 0.;
   double scale_temp = 0.;
   double diffcross = 0., err_diffcross = 0.;
   double cross = 0., err_cross = 0., scale1_temp = 0.;
   binsize = HData->GetNbinsX(); 
   for (int i = 1;i<=binsize; i++) {
   	nbdata = HData->GetBinContent(i);
   	errdata = HData->GetBinError(i);
   	
   	mvalue = axis_hhdata->GetBinCenter(i)/1000.;
   	m_list[i-1] = mvalue;
   	
   	Nsig_gen = HOmegam_gen->GetBinContent(i);
   	Nsig_rec = HOmegam->GetBinContent(i);
   	efficy = Nsig_rec/Nsig_gen;
   	efficy_list[i-1]=efficy;
   	
   	xlow = axis_hhdata->GetBinLowEdge(i);
		xupp = axis_hhdata->GetBinUpEdge(i);
		x.setRange("intrange",xlow,xupp); // set range
		// calculate bkgsum content and error
		RooAbsReal* fracBkgsumRange_bin = bkgsum.createIntegral(x,x,"intrange"); // integrate			
		fbkg = fracBkgsumRange_bin->getVal(); // get bkgsum fraction
   	err_fbkg = fracBkgsumRange_bin->getPropagatedError(*rf); // get  bkgsum error
   	
   	Nbkg_sel = Nbbkgsum*fbkg;
   	err_nbkg_sel = TMath::Sqrt((fbkg*err_Nbbkgsum)*(fbkg*err_Nbbkgsum)+(err_fbkg*Nbbkgsum)*(err_fbkg*Nbbkgsum));
   	Nsig_sel = nbdata - Nbkg_sel;
   	
   	if (efficy != 0.) {
   		//std::cout<<"Nsig_rec = "<<Nsig_rec<<endl;
   		scale_temp = 1./(binwidth_temp*efficy*intlumi);
   	}
   	else {
   		scale_temp = 0.;
   	}
   	
   	diffcross = scale_temp*Nsig_sel;
   	err_diffcross = scale_temp*TMath::Sqrt(errdata*errdata+err_nbkg_sel*err_nbkg_sel);
   	//err_diffcross = 1.;
   	
   	HDiffCross->SetBinContent(i,diffcross);
   	HDiffCross->SetBinError(i,err_diffcross);
   	
   	// get isr correction
   	isr_list[i-1] = getWfunc(&mvalue);  	
   	scale1_temp = (sqrtS*sqrtS/(2*mvalue))*1e3/isr_list[i-1];
   	cross = scale1_temp*diffcross;
   	err_cross = scale1_temp*err_diffcross;
   	
   	HCross->SetBinContent(i,cross);
   	HCross->SetBinError(i,err_cross);
		std::cout<<"--------------------------------------------------"<<endl;
   	std::cout<<"Bin ["<<i<<"]: \n"<<"nb data = "<<nbdata<<" +/- "<<errdata<<endl;
   	std::cout<<"expected total number of bkg = "<<Nbbkgsum<<" +/- "<<err_Nbbkgsum<<endl;
   	std::cout<<"fraction of bkg in mass sub range = "<<fbkg<<" +/- "<<err_fbkg<<endl;
   	std::cout<<"selected bkg = "<<Nbkg_sel<<" +/- "<<err_nbkg_sel<<endl;
   	std::cout<<"selected omgam = "<<Nsig_sel<<endl;
   	
   	std::cout<<"mass bin width = "<<binwidth_temp<<" MeV"<<endl;
   	std::cout<<"generated omegam = "<<Nsig_gen<<", reconstruted after cuts = "<<Nsig_rec<<endl;
   	
   	std::cout<<"efficiency = "<<efficy_list[i-1]<<endl;
   	std::cout<<"scacle factor = "<<scale_temp<<endl;
   	std::cout<<"differential cross section = "<<HDiffCross->GetBinContent(i)<<" +/- "<<HDiffCross->GetBinError(i)<<endl;
   	std::cout<<"isr correction = "<<isr_list[i-1]<<endl;
   	
   	std::cout<<"c.o.m energy = "<<sqrtS<<" GeV"<<endl;
   	std::cout<<"mvalue = "<<mvalue<<" GeV"<<endl;
   	std::cout<<"scacle1 factor = "<<scale1_temp<<endl;
   	std::cout<<"cross section = "<<HCross->GetBinContent(i)<<" +/- "<<HCross->GetBinError(i)<<endl;
   }
   
   
   // Breit-Wigner
   RooRealVar m0( "m0", "m0", 782.65, 750.,800.);
   RooRealVar width( "width", "width", 8.49,5.,10. );
   RooBreitWigner bw( "bw", "bw", x, m0, width );
	
	// Construct convolution
	RooRealVar bw_frac("bw_frac","fraction",0.5,0.,1.); 
	 
	RooFFTConvPdf bwg("bwg","bwg",x,bw,gauss); 
	
	RooDataHist hcross("hcross","hcross",x,Import(*HCross));
	
	RooRealVar totalcross("totalcross","integrated cross section",10000,0.,100000.);
	RooAddPdf model1("model1","model1",bwg,totalcross);
	RooFitResult* rf1 = model1.fitTo(hcross,Extended(),Save()); 
	
	/// fit cross section
   // get bin number of fit range
   int bin_subrange1 = 0., bin_subrange2 = 0.;
   bin_subrange1 = axis_hhdata->FindBin(subrange1); 
   bin_subrange2 = axis_hhdata->FindBin(subrange2);
   std::cout<<"mvalue of subrange1 = "<<subrange1<<" at bin ["<<bin_subrange1<<"]"<<endl;
   std::cout<<"mvalue of subrange2 = "<<subrange2<<" at bin ["<<bin_subrange2<<"]"<<endl;
   // get norlization factor		
	double norfactor = totalcross.getVal();
	// integrate pdf model1 over entire subrange [subrange1, subrange2]
	std::cout<<"normalization factor = "<<norfactor<<endl;
	
	RooAbsReal* fracCrossRange = model1.createIntegral(x,x,"crossrange"); // integrate			
	double frac_cross = fracCrossRange->getVal(); // get fraction
	std::cout<<"normalization pdf value = "<<frac_cross<<endl;
   for (int i = bin_subrange1;i<=bin_subrange2;i++) {
   	std::cout<<"bin ["<<i<<"]"<<endl;
   }
	
	/// Draw all frames on a canvas
	RooPlot* frame = x.frame(); 
	data.plotOn(frame);
	model.plotOn(frame,Name("model"),LineStyle(kSolid),LineColor(kRed));
	model.plotOn(frame,Name("sig"),Components("sig"),LineStyle(kSolid),LineColor(4));
	model.plotOn(frame,Name("bkgsum"),Components("bkgsum"),LineStyle(kSolid),LineColor(1));
	model.plotOn(frame,Name("threepigampdf"),Components("threepigampdf"),LineStyle(kDashed),LineColor(6));
	model.plotOn(frame,Name("omegpipdf"),Components("omegpipdf"),LineStyle(kDashed),LineColor(7));
	model.plotOn(frame,Name("kslpdf"),Components("kslpdf"),LineStyle(kDashed),LineColor(20));
	model.plotOn(frame,Name("mcrestpdf"),Components("mcrestpdf"),LineStyle(kDashed),LineStyle(kDashed),LineColor(5));
	
	RooPlot* frame1 = x.frame();
	data.plotOn(frame1);
	
	TCanvas* c = new TCanvas("IMfit","IMfit",800,400);
	frame->GetXaxis()->SetTitle("M_{3#pi} [MeV]");	
	frame->GetYaxis()->SetTitle(TString::Format("Entries/%0.1f [MeV]",binwidth_temp));
	c->Divide(1); 
   c->cd(1); 
   frame->Draw();
   
   /*TCanvas* c1 = new TCanvas("DiffCross","differential cross section",800,400);
	HDiffCross->GetXaxis()->SetTitle("M_{3#pi} [MeV]");	
	HDiffCross->GetYaxis()->SetTitle(TString::Format("d#sigma_{#omega#gamma}/dm #times %0.1f [MeV]",binwidth_temp));
	c1->Divide(2,1); 
   c1->cd(1); 
   HDiffCross->Draw();
   
   c1->cd(2); 
   HCross->Draw();
   
	TCanvas *c2 = new TCanvas("c2","isr correction",700,700);
	auto gf= new TGraph(binnb,m_list,isr_list);
	gf->GetYaxis()->SetTitleOffset(1.4);
	//gf->GetXaxis()->SetTitle(xname[modpos]);
	gf->GetXaxis()->SetTitle("M(3#pi) [MeV]");
	gf->GetYaxis()->SetTitle("W(s,m)");	
	gf->SetMarkerSize(0.4);
	gf->SetMarkerStyle(21);
	gf->SetLineColor(2);
	gf->Draw("AP");

	TCanvas *c4 = new TCanvas("c4","efficiency",700,700);
	auto gf= new TGraph(binnb,m_list,efficy_list);
	gf->GetYaxis()->SetTitleOffset(1.4);
	//gf->GetXaxis()->SetTitle(xname[modpos]);
	gf->GetXaxis()->SetTitle("M(3#pi) [MeV]");
	gf->GetYaxis()->SetTitle("W(s,m)");	
	gf->SetMarkerSize(0.4);
	gf->SetMarkerStyle(21);
	gf->SetLineColor(2);
	gf->Draw("AP");*/
	
	TCanvas* c5 = new TCanvas("c5","born cross section",800,400);
	RooPlot* frame2 = x.frame();
	frame2->GetXaxis()->SetTitle("M_{3#pi} [MeV]");	
	frame2->GetYaxis()->SetTitle(TString::Format("#sigma(e^{+}e^{-}#rightarrow#omega#gamma#rightarrow#pi^{+}#pi^{-}#pi^{0}#gamma) [nb]"));
	//frame2->GetXaxis()->SetRangeUser(subrange1,subrange2);	
	c5->Divide(1);
	c5->cd(1);
	hcross.plotOn(frame2); 
	bwg.plotOn(frame2,Name("bwg"));
	frame2->Draw("Same");
	
	HCross->GetXaxis()->SetRangeUser(subrange1,subrange2);
	//c5->cd(1);
	//HCross->Draw();
	
	TFile hf("./ROOT/HISTOS1.root","recreate");
   HCross->Write();
}	
