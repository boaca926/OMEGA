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


void cross_new() {
	gStyle->SetOptTitle(0);
	/// variables
	double threepiIM = 0.;
	double threepiIMreso = Resolu[0];
	RooRealVar x("ThreepiIM","ThreepiIM",xmin_IM,xmax_IM);
	RooRealVar y("IMthreepi_MC","IMthreepi_MC",xmin_IM,xmax_IM);
	const Int_t binnb = 100;
	/// get root files
	TFile *findFile = new TFile("./ROOT/TREE_cutted.root","READ");
	TFile *findFile1 = new TFile("./ROOT/TREE_Gen.root","READ");
	x.setBins(binnb); y.setBins(binnb);
	double binwidth_temp = (xmax_IM-xmin_IM)/binnb;
	std::cout<<"BIN WIDTH = "<<binwidth_temp<<" MeV"<<endl;
	x.setBins(1000000,"fft") ;
	
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
   RooRealVar sg("sg","sg",threepiIMreso,0.,5.);
	RooGaussian gauss("gauss","gauss",x,mg,sg);
	
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
	RooFFTConvPdf omegampdfcov("omegampdffcov","omegam (X) gauss",x,omegampdf,gauss);
   
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
   RooAddPdf sig("sig","Signal",omegampdf,sigfrac);
	RooAddPdf bkgsum("bkgsum","bkgsum",RooArgList(omegpipdf,kslpdf,mcrestpdf,threepigampdf,threepigampdf),RooArgList(fomegpi,fksl,fmcrest,fthreepigam));
	RooAddPdf model("model","model",RooArgList(sig,bkgsum),RooArgList(nsig,nbkgsum));
	// fit
   RooFitResult* rf = model.fitTo(data,Extended(),Save());
   RooArgSet* params = model.getVariables();
   params->Print("v");
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
   double binsize = 0., nbdata = 0., errdata = 0.;
   double fsig_bin = 0., err_nbsig_bin = 0.;
   double fbkgsum_bin = 0., fbkgsum_bin = 0.;
   TAxis* axis_hhdata = HData->GetXaxis();
   binsize = HData->GetNbinsX();   
   // create histo for expected total number of signal
   TH1D* HNsigexp_bin = new TH1D("HNsigexp_bin","Total expected number of omegam events",binnb,xmin_IM,xmax_IM); HNsigexp_bin->Sumw2();
   // create histo for signal fraction
   TH1D* HFracsig_bin = new TH1D("HFracsig_bin","Omegam fraction",binnb,xmin_IM,xmax_IM); HFracsig_bin->Sumw2();
   // create histo for expected total number of bkgsum
   TH1D* HNbkgsumexp_bin = new TH1D("HNbkgsumexp_bin","Total expected number of bkgsum events",binnb,xmin_IM,xmax_IM); HNbkgsumexp_bin->Sumw2();
   // create histo for bkgsum fraction
   TH1D* HFracbkgsum_bin = new TH1D("HFracbkgsum_bin","bkgsum fraction",binnb,xmin_IM,xmax_IM); HFracbkgsum_bin->Sumw2();  
   // create histo for selected number of signal
   TH1D* HNsigsel_bin = new TH1D("HNsigsel_bin","Total selected number of omegam events",binnb,xmin_IM,xmax_IM); HNsigsel_bin->Sumw2();
   // create histo for filling total luminosity L
   TH1D* HLumi_bin = new TH1D("HLumi_bin","Integrated luminosity L",binnb,xmin_IM,xmax_IM); HLumi_bin->Sumw2();
   std::cout<<"data histo. bin size = "<<binsize<<endl;
   for (int i = 1;i<=binsize; i++) {
   //for (int i = 1;i<=20; i++) {
   	nbdata = HData->GetBinContent(i);
   	errdata = HData->GetBinError(i);
   	// fill HNsigexp_bin
   	HNsigexp_bin->SetBinContent(i,Nbsig);
   	HNsigexp_bin->SetBinError(i,err_Nbsig);
  
  		// fit HNbkgsumexp_bin
  		HNbkgsumexp_bin->SetBinContent(i,Nbbkgsum);
   	HNbkgsumexp_bin->SetBinError(i,err_Nbbkgsum);
   	
   	xlow = axis_hhdata->GetBinLowEdge(i);
		xupp = axis_hhdata->GetBinUpEdge(i);
		x.setRange("intrange",xlow,xupp); // set range
		// calculate sig content and error
		RooAbsReal* fracSigRange_bin = sig.createIntegral(x,x,"intrange"); // integrate			
		fsig_bin = fracSigRange_bin->getVal(); // get sig fraction
		//cout<<fsig_bin<<endl;
		err_nbsig_bin = fracSigRange_bin->getPropagatedError(*rf); // get sig sum error
		  
		// fill HFracsig_bin
		HFracsig_bin->SetBinContent(i,fsig_bin);
		HFracsig_bin->SetBinError(i,err_nbsig_bin);
		
		// calculate bkgsum content and error
		RooAbsReal* fracBkgsumRange_bin = bkgsum.createIntegral(x,x,"intrange"); // integrate			
		fbkgsum_bin = fracBkgsumRange_bin->getVal(); // get bkgsum fraction
		//cout<<fbkgsum_bin<<endl;
		err_nbbkgsum_bin = fracBkgsumRange_bin->getPropagatedError(*rf); // get  bkgsum error
		
		// fill HFracbkgsum_bin
		HFracbkgsum_bin->SetBinContent(i,fbkgsum_bin);
		HFracbkgsum_bin->SetBinError(i,err_nbbkgsum_bin);
		
		// fill HNsigsel_bin
		HNsigsel_bin->SetBinContent(i,nbdata);
   	HNsigsel_bin->SetBinError(i,errdata);
		
		// fill HLumi_bin
		HLumi_bin->SetBinContent(i,intlumi);
		
		// check propagated error for nbsigsel = nbsigexp*fraction
		double nbsig_bin_temp = Nbsig*fsig_bin;
		double Sigma_1 = fsig_bin*HNsigexp_bin->GetBinError(i);
		double Sigma_2 = Nbsig*HFracsig_bin->GetBinError(i);
		double Sigma_nbsigsel = Sigma_1*Sigma_1+Sigma_2*Sigma_2;
		double sigma_nbsigsel = TMath::Sqrt(Sigma_nbsigsel);
			
		std::cout<<"--------------------------------------------------"<<endl;
   	std::cout<<"Bin ["<<i<<"]: "<<"nb data = "<<nbdata<<" error_data = "<<errdata<<endl;  
   	std::cout<<"integrate range "<<"["<<xlow<<", "<<xupp<<"]"<<endl;	
   	sted::cout<<"expected omegam events = "<<HNsigexp_bin->GetBinContent(i)<<"+/-"<<HNsigexp_bin->GetBinError(i)<<endl;
   	sted::cout<<"bkgsum fraction = "<<HFracbkgsum_bin->GetBinContent(i)<<"+/-"<<HFracbkgsum_bin->GetBinError(i)<<endl;
   	sted::cout<<"selected omegam = "<<nbsig_bin_temp<<"+/-"<<sigma_nbsigsel<<endl;
   	sted::cout<<"expected bkgsum events = "<<HNbkgsumexp_bin->GetBinContent(i)<<"+/-"<<HNbkgsumexp_bin->GetBinError(i)<<endl;
   	
   }
   // get HNbkgsumsel_bin
   TH1D* HNbkgsumsel_bin=(TH1D*)HNbkgsumexp_bin->Clone();
   HNbkgsumsel_bin->Multiply(HNbkgsumsel_bin,HFracbkgsum_bin,1.0,1.0);
   // get HNsigsel_bin
   HNsigsel_bin->Add(HNbkgsumsel_bin,-1);
   // create histo for filling efficiency
   TH1D* Heffcy_bin = new TH1D("Heffcy_bin","Globle efficiency epsilon",binnb,xmin_IM,xmax_IM); Heffcy_bin->Sumw2();
   // create a list store efficiency errros
   double list[binnb];
   // create histo for efficiency corrected HNsigsel_bin
   TH1D* HNsigselcorr_bin = new TH1D("HNsigselcorr_bin","efficiency corrected dN/dm omgam",binnb,xmin_IM,xmax_IM); HNsigselcorr_bin->Sumw2();
   for (int i = 1;i<=binsize; i++) {
   //for (int i = 1;i<=20; i++) {
   	// fill Heffcy_bin
		effic_bin = HOmegam->GetBinContent(i)/HOmegam_gen->GetBinContent(i);
		err_effic_bin = (1.0/HOmegam_gen->GetBinError(i))*TMath::Sqrt
(effic_bin*(1-effic_bin));
		Heffcy_bin->SetBinContent(i,effic_bin);
		// fill HNsigselcorr_bin
		HNsigselcorr_bin->SetBinContent(i,HNsigsel_bin->GetBinContent(i));
		HNsigselcorr_bin->SetBinError(i,HNsigsel_bin->GetBinError(i));
		std::cout<<"--------------------------------------------------"<<endl;
   	std::cout<<"Bin ["<<i<<"]: "<<"selected bkgsum = "<<HNbkgsumsel_bin->GetBinContent(i)<<"+/-"<<HNbkgsumsel_bin->GetBinError(i)<<endl;
   	std::cout<<"Generated sig = "<<HOmegam_gen->GetBinContent(i)<<", selected sig = "<<HOmegam->GetBinContent(i)<<", efficiency = "<<effic_bin<<"+/-"<<err_effic_bin<<endl;
   }  
   // get HNsigselcorr_bin
   HNsigselcorr_bin->Divide(HNsigselcorr_bin,Heffcy_bin);
   // create histo for differential cross section
   TH1D* HDiffCross_bin = new TH1D("HDiffCross_bin","differential cross sectionomgam",binnb,xmin_IM,xmax_IM); HDiffCross_bin->Sumw2();
   // create a list store isr correction
   double isr_list[binnb];
   double m_list[binnb];
   //
   double mvalue = 0., Wvalue = 0.;
   for (int i = 1;i<=binsize; i++) {
   //for (int i = 1;i<=20; i++) {
   	// fill HDiffCross_bin
   	HDiffCross_bin->SetBinContent(i,HNsigselcorr_bin->GetBinContent(i));
		HDiffCross_bin->SetBinError(i,HNsigselcorr_bin->GetBinError(i));
		//
		mvalue = axis_hhdata->GetBinCenter(i)/1000.;
		Wvalue = getWfunc(&mvalue);
		isr_list[i-1]=Wvalue;
		m_list[i-1]=mvalue;
		//std::cout<<"m value = "<<m_list[i-1]<<", W value = "<<isr_list[i-1]<<endl;
		std::cout<<"Bin ["<<i<<"]: "<<"differential cross section = "<<HDiffCross_bin->GetBinContent(i)<<" +/- "<<HDiffCross_bin->GetBinError(i)<<endl;
   } 
   // get HNsigselcorr_bin
   HDiffCross_bin->Divide(HDiffCross_bin,HLumi_bin);
   
   
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
	
	TCanvas* c = new TCanvas("IMfit","IMfit",800,400);
	frame->GetXaxis()->SetTitle("M_{3#pi} [MeV]");	
	frame->GetYaxis()->SetTitle(TString::Format("Entries/%0.1f [MeV]",binwidth_temp));
	c->Divide(1); 
   c->cd(1); 
   frame->Draw();
	
	/// draw histos
	TLine *l = new TLine(xmin_IM,0.0,xmax_IM,0.0); format_l(l,2,2,2);
   
   
  
   TCanvas* d = new TCanvas("histos","expected bkgsum and total luminosity",800,400);
	d->Divide(2,1); 
   d->cd(1);
   HNbkgsumexp_bin->GetXaxis()->SetTitle("M_{3#pi} [MeV]");
   HNbkgsumexp_bin->GetYaxis()->SetTitle(TString::Format("Entries%0.1f [MeV]",binwidth_temp));
   HNbkgsumexp_bin->Draw();
   
   d->cd(2);
   HLumi_bin->GetXaxis()->SetTitle("M_{3#pi} [MeV]");
	HLumi_bin->GetYaxis()->SetTitle("pb^{-1}");
   HLumi_bin->Draw();
   
   TCanvas* c3 = new TCanvas("diffcross","Diffential cross section",800,400);
	c3->Divide(3,3); 
	
   c3->cd(1);
   HData->Draw();
   
   c3->cd(2);
   TH1D* HFracbkgsum_binCL=HFracbkgsum_bin->Clone();
   HFracbkgsum_bin->GetXaxis()->SetTitle("M_{3#pi} [MeV]");
   HFracbkgsum_bin->GetYaxis()->SetTitle("bkg fraction");
   HFracbkgsum_bin->SetFillColor(7); // or any other color
	HFracbkgsum_bin->Draw("e4");
	HFracbkgsum_binCL->SetMarkerStyle(kFullCircle);
	HFracbkgsum_binCL->SetMarkerSize(0.5);
	HFracbkgsum_binCL->Draw("histo p same"); 
	
	c3->cd(3);
	TH1D* HNbkgsumsel_binCL=HNbkgsumsel_bin->Clone();
   HNbkgsumsel_bin->GetXaxis()->SetTitle("M_{3#pi} [MeV]");
   HNbkgsumsel_bin->GetYaxis()->SetTitle(TString::Format("#epsilon #times dN_{bkg}/dm #times %0.1f [MeV]",binwidth_temp));
   //HNbkgsumsel_bin->GetYaxis()->SetTitle(TString::Format("#epsilon#dotdN_{#omega#gamma_{ISR}}/dm#times%0.1f [MeV]",binwidth_temp));
   HNbkgsumsel_bin->SetFillColor(7); // or any other color
	HNbkgsumsel_bin->Draw("e4");
	HNbkgsumsel_binCL->SetMarkerStyle(kFullCircle);
	HNbkgsumsel_binCL->SetMarkerSize(0.5);
	HNbkgsumsel_binCL->Draw("histo p same");
	
	c3->cd(4);
	HNsigsel_bin->GetXaxis()->SetTitle("M_{3#pi} [MeV]");
   HNsigsel_bin->GetYaxis()->SetTitle(TString::Format("#epsilon #times d#sigma_{#omega#gamma}/dm #times %0.1f [MeV]",binwidth_temp));
	HNsigsel_bin->Draw();
	l->Draw("Same");
	
	c3->cd(5);
   HOmegam_gen->GetXaxis()->SetTitle("M_{3#pi} [MeV]");
   HOmegam_gen->GetYaxis()->SetTitle(TString::Format("Entries/%0.1f [MeV]",binwidth_temp));
   HOmegam_gen->Draw("histo");
   
   c3->cd(6);
   HOmegam->GetXaxis()->SetTitle("M_{3#pi} [MeV]");
   HOmegam->GetYaxis()->SetTitle(TString::Format("Entries/%0.1f [MeV]",binwidth_temp));
   HOmegam->Draw("histo");
   
   c3->cd(7);
   Heffcy_bin->SetMarkerStyle(kFullCircle);
   Heffcy_bin->SetMarkerSize(0.35);
   Heffcy_bin->Draw("P");
	
	c3->cd(8);
	HNsigselcorr_bin->GetXaxis()->SetTitle("M_{3#pi} [MeV]");
   HNsigselcorr_bin->GetYaxis()->SetTitle(TString::Format(" d#N_{#omega#gamma}/dm #times %0.1f [MeV]",binwidth_temp));
	HNsigselcorr_bin->Draw();
	l->Draw("Same");

   Double_t chi2 = frame->chiSquare(7);
   std::cout<<"chi2 value = "<<chi2<<", ndf = "<<7<<endl;
   
   c3->cd(9);
   HDiffCross_bin->Draw();
   
	TCanvas *c4 = new TCanvas("c4","optimization of chi2 cut",700,700);
	auto gf= new TGraph(binnb,m_list,isr_list);
	gf->GetYaxis()->SetTitleOffset(1.4);
	//gf->GetXaxis()->SetTitle(xname[modpos]);
	gf->GetXaxis()->SetTitle("M(3#pi) [MeV]");
	gf->GetYaxis()->SetTitle("W(s,m)");	
	gf->SetMarkerSize(0.4);
	gf->SetMarkerStyle(21);
	gf->SetLineColor(2);
	gf->Draw("AP");

	
   
   TFile hf("./ROOT/HISTOS1.root","recreate");
   HDiffCross_bin->Write();
}	
