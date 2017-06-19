#include "Getname.C"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
#include "gethisto.C"

gSystem->Load("libRooFit");
using namespace std;
using namespace RooFit;

void cross() {
	gStyle->SetOptTitle(0);
	
	Double_t threepiIM = 0.;
	TString SIMthreepi = getbraname(1);
	TString SThreepiIM = getbraname(9);//  
	// get root file
	TFile *findFile = new TFile("./ROOT/TREE_cutted.root","READ");
	TFile *findFile1 = new TFile("./ROOT/TREE_Gen.root","READ");
	// get trees 
	TString Omegpi = gettreename(0);// omega pi0
	TString Ksl = gettreename(2);// KSL
	TString Omegam = gettreename(3);// omega gamma
	TString Data = gettreename(10);// data
	TString MCrest = gettreename(7);// mc rest = bkgsum2
	
	TTree *TData = (TTree*)findFile->Get("T"+Data+"_Pre"); // data
	TTree *TKsl = (TTree*)findFile->Get("T"+Ksl+"_Pre");
	TTree *TOmegpi = (TTree*)findFile->Get("T"+Omegpi+"_Pre");// omegapi
	TTree *TOmegam = (TTree*)findFile->Get("T"+Omegam+"_Pre"); // omega gamma
	TTree *TMCrest = (TTree*)findFile->Get("T"+MCrest+"_Pre"); // MCrest
	TTree *TOmegam_Gen = (TTree*)findFile1->Get("T"+Omegam+"_MC"); // omega gamma MC true
	
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
	
	TOmegam_Gen->SetBranchAddress(SIMthreepi+"_MC",&threepiIM);
	
	// declear variable
	RooRealVar x("ThreepiIM","ThreepiIM",xmin_IM,xmax_IM);
	RooRealVar y("IMthreepi_MC","IMthreepi_MC",xmin_IM,xmax_IM);
	const int binnb=50;
	x.setBins(binnb); y.setBins(binnb);
	double binwidth_temp = (xmax_IM-xmin_IM)/binnb;
	//cout<<binwidth_temp<<endl;
	
	// data	
	double N_d=0;
	for (Int_t irow=0;irow<TData->GetEntries();irow++) {
		TData->GetEntry(irow); 
		N_d++;
   }
   std::cout<<"N_d = "<<N_d<<endl;
   
   RooDataSet data("data","data",RooArgSet(x),Import(*TData));
	RooDataHist* hdata = data.binnedClone();
	RooHistPdf hdatapdf("hdatapdf","hdatapdf",x,*hdata,0);
	TH1D* hhdata = hdata->createHistogram("ThreepiIM",binnb);
	TH1D* HNbkgsum = new TH1D("HNbkgsum","bkg sum in histo",binnb,xmin_IM,xmax_IM);
	TH1D* Hfbkgsum_bin = new TH1D("Hfbkgsum_bin","bkg sum fraction in histo",binnb,xmin_IM,xmax_IM);
	
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
   for (Int_t irow=0;irow<TOmegam->GetEntries();irow++) {
   	TOmegam->GetEntry(irow); 
   	N_omegam++;	
   }
   fomegam_init=N_omegam/N_d; 
   std::cout<<"N_omegam = "<<N_omegam<<", fomegam_init = "<<fomegam_init<<endl;
   
   RooDataSet omegam("omegam","omegam",TOmegam,x);
   RooKeysPdf omegampdf("omegampdf", "omegampdf", x, omegam, RooKeysPdf::MirrorBoth, 1);
   RooDataHist* homegam = omegam.binnedClone();
	RooHistPdf homegampdf("homegampdf","homegampdf",x,*homegam,0);
	TH1D* hhomegam = homegam->createHistogram("ThreepiIM",binnb);
   
   // omegam generated
   double N_omegam_gen = 0;
   for (Int_t irow=0;irow<TOmegam_Gen->GetEntries();irow++) { 
   	TOmegam_Gen->GetEntry(irow);
   	N_omegam_gen++;
   	//cout<<threepiIM<<endl;
   }
   std::cout<<"N_omegam_gen = "<<N_omegam_gen<<endl;
   RooDataSet omegamgen("omegamgen","omegamgen",RooArgSet(y),Import(*TOmegam_Gen));
   RooDataHist* homegamgen = omegamgen.binnedClone();
	RooHistPdf homegamgenpdf("homegamgenpdf","homegamgenpdf",y,*homegamgen,0);
	TH1D* hhomegamgen = homegamgen->createHistogram("IMthreepi_MC",binnb);
   
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
   RooRealVar c0("c0","coefficient #0", -0.1,-10.,10.); 
	RooRealVar c1("c1","coefficient #1", -0.1,-10.,10.); 
	RooRealVar c2("c2","coefficient #2", -0.1,-10.,10.); 
	RooChebychev threepigampdf("threepigampdf","threepigampdf",x,RooArgList(c0,c1,c2));
	
   /*RooRealVar a0("a0","a0",0.5,-10.,10.) ;
   RooRealVar a1("a1","a1",-0.2,-10.,10.) ;
   RooChebychev threepigampdf("threepigampdf","threepigampdf",x,RooArgSet(a0,a1));*/
   
   fthreepigam_init=1-fomegpi_init-fomegam_init;
   std::cout<<"fthreepigam_init = "<<fthreepigam_init<<endl;
   
   // constrcut model for fit in control region [xmin fitcut]
   RooRealVar fksl("fksl","ksl fraction",fksl_init);
   RooRealVar fomegpi("fomegpi","omegpi fraction",fomegpi_init); 
   RooRealVar fomegam("fomegam","fomegam fraction",fomegam_init);
   RooRealVar fmcrest("fmcrest","mcrest fraction",fmcrest_init);
   RooRealVar fthreepigam("fthreepigam","threepigam fraction",fthreepigam_init);
   RooRealVar sigfrac("sigfrac","signal fraction",fomegam_init);
   RooAddPdf sig("sig","Signal",omegampdf,sigfrac);
   RooAddPdf bkgsum("bkgsum","bkgsum",RooArgList(omegpipdf,threepigampdf),RooArgList(fomegpi,fthreepigam));
   //RooAddPdf model("model","model",RooArgList(sig,bkgsum),fomegam);
   RooRealVar nsig("nsig","signal fraction",10000,0.,100000.) ;
	RooRealVar nbkgsum("nbkgsum","background fraction",10000,0.,100000.) ;
	RooAddPdf model("model","model",RooArgList(sig,bkgsum),RooArgList(nsig,nbkgsum));
	//RooAddPdf model("model","model",RooArgList(sig,bkgsum),sigfrac);
	// fit
   RooFitResult* rf = model.fitTo(data,Extended(),Save());
   //RooFitResult* rf = model.fitTo(data);
   //model.Print("t");
   RooArgSet* params = model->getVariables();
   params->Print("v") ;
   // cross section
   // loop over all bins in data and test errors
   double nbdata = 0, binsize = 0, entries = 0, errdata = 0;
   double xlow = 0, xupp = 0, sigfrac_bin = 0;
   double nbbkg = 0, err_nbbkg = 0;
   double fbkg_bin = 0, nbbkg_bin = 0, err_nbbkg_bin=0;;
   // check bin size of the data histo
   TAxis* axis = hhdata->GetXaxis();
   binsize = hhdata->GetNbinsX(); entries=getentriesfit(hhdata);
   nbbkg = nbkgsum.getVal();
   err_nbbkg = nbkgsum.getError();
   std::cout<<"<<<<<<<<<<<<< bin size = "<<binsize<<" <<<<<<<<<<<<<<"<<endl;
   std::cout<<"total # data = "<<entries<<endl;
   std::cout<<"expected bkg sum = "<<nbbkg<<"+/-"<<err_nbbkg<<endl;
   // create histos

   std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
   for (int i = 1;i<=binsize; i++) {
   //for (int i = 1;i<=2; i++) {
   	// get bin content from data histo
   	nbdata = hhdata->GetBinContent(i);
   	errdata = hhdata->GetBinError(i);
   	// calculate bkg content
   	xlow = axis->GetBinLowEdge(i);
		xupp = axis->GetBinUpEdge(i);
		x.setRange("intrange",xlow,xupp) ; // set range
		RooAbsReal* fracBkgRange_bin = bkgsum.createIntegral(x,x,"intrange"); // integrate
		fbkg_bin = fracBkgRange_bin->getVal(); // get bkg sum fraction
		nbbkg_bin = fbkg_bin*nbbkg; // get bkg sum number
		err_nbbkg_bin = fracBkgRange_bin->getPropagatedError(*rf); // get bkg sum error
		// fill HNbkgsum histo
		HNbkgsum->SetBinContent(i,nbbkg);
		HNbkgsum->SetBinError(i,err_nbbkg);
		// fill bkgsum fraction and fill in histo called Hfbkgsum_bin histo
		Hfbkgsum_bin->SetBinContent(i,fbkg_bin);
		Hfbkgsum_bin->SetBinError(i,err_nbbkg_bin);
		// multiply total bkgsum and fraction histo to get expected bkgsum number and fill in histo called HNbkgsum_bin
		//cout<<HNbkgsum->GetBinContent(i)<<"+/-"<<HNbkgsum->GetBinError(i)<<endl;
		/*std::cout<<"--------------------------------------------------"<<endl;
		std::cout<<"bin number = "<<i<<endl;
		std::cout<<"data bin content = "<<nbdata<<endl;
   	std::cout<<"data bin error = "<<errdata<<"\n"<<endl;
		std::cout<<"integrate range "<<"["<<xlow<<", "<<xupp<<"]"<<endl;
		sted::cout<<"expected bkg sum fraction = "<<Hfbkgsum_bin->GetBinContent(i)<<"+/-"<<Hfbkgsum_bin->GetBinError(i)<<endl;*/
   }
   //HNbkgsum->Sumw2();
	//Hfbkgsum_bin->Sumw2();
	TH1D *HNbkgsum_bin=(TH1D*)HNbkgsum->Clone();
   HNbkgsum_bin->Multiply(HNbkgsum_bin,Hfbkgsum_bin,1.0,1.0);
   //HNbkgsum_bin->Sumw2();
   //hhdata->Sumw2();
   TH1D *HNsig_bin=(TH1D*)hhdata->Clone();
   //HNsig_bin->Sumw2();
   HNsig_bin->Add(HNbkgsum_bin,-1);
   // get efficiency histogram
   //hhomegam->Sumw2();
   //hhomegamgen->Sumw2();
   TH1D *Heffcy_bin=(TH1D*)hhomegam->Clone();
   Heffcy_bin->Divide(Heffcy_bin,hhomegamgen);
   double error_nbomegam_gen = 0, p_nbomegam = 0, error_effic_omegam = 0;
   for (int i = 1;i<=binsize;i++) {
   //for (int i = 1;i<=20; i++) {
   	std::cout<<"--------------------------------------------------"<<endl;
   	//sted::cout<<"expected # bkg sum  = "<<HNbkgsum_bin->GetBinContent(i)<<"+/-"<<HNbkgsum_bin->GetBinError(i)<<endl;
   	error_nbomegam_gen = hhomegamgen->GetBinError(i);
   	p_nbomegam = hhomegam->GetBinContent(i)/hhomegamgen->GetBinContent(i);
   	error_effic_omegam = 1.0/error_nbomegam_gen*TMath::Sqrt
(p_nbomegam*(1-p_nbomegam)); // calculate binomial error
		Heffcy_bin->SetBinError(i,error_effic_omegam);
   	//cout<<error_nbomegam_gen<<endl;
   	//cout<<effic_omegam<<endl;
   	//cout<<p_nbomegam<<endl;
   	sted::cout<<"omegam generated  = "<<hhomegamgen->GetBinContent(i)<<"+/-"<<error_nbomegam_gen<<endl;
   	sted::cout<<"omegam reconst.  = "<<hhomegam->GetBinContent(i)<<"+/-"<<hhomegam->GetBinError(i)<<endl;
   	sted::cout<<"omegam efficiency  = "<<Heffcy_bin->GetBinContent(i)<<"+/-"<<Heffcy_bin->GetBinError(i)<<endl;
   }
	
	//
	//sigfrac_bin = fracSigRange_bin->getVal();
	//RooAbsPdf* paramPdf= rf->createHessePdf(RooArgSet(c0,c1,c2)); 
	//Double_t err =  fracSigRange_bin->getPropagatedError(*rf);
	//std::cout<<"/////////////"<<fracSigRange_bin->getVal()<<endl;
	//std::cout<<"/////////////"<<err<<endl;
   // Draw all frames on a canvas
	RooPlot* frame = x.frame(); 
	data.plotOn(frame);
	/*kslpdf.plotOn(frame,LineStyle(kSolid),LineColor(15));
	omegpipdf.plotOn(frame,LineStyle(kSolid),LineColor(7));
	omegampdf.plotOn(frame,LineStyle(kSolid),LineColor(4));
	mcrestpdf.plotOn(frame,LineStyle(kSolid),LineColor(20));*/
	
	model.plotOn(frame,Name("model"),LineStyle(kSolid),LineColor(kRed));
	model.plotOn(frame,Name("omegpipdf"),Components("omegpipdf"),LineStyle(kDashed),LineColor(7));
	//model.plotOn(frame,Name("kslpdf"),Components("kslpdf"),LineStyle(kSolid),LineColor(15));
	model.plotOn(frame,Name("sig"),Components("sig"),LineStyle(kSolid),LineColor(4));
	//model.plotOn(frame,Name("mcrestpdf"),Components("mcrestpdf"),LineStyle(kSolid),LineColor(20));	
	model.plotOn(frame,Name("threepigampdf"),Components("threepigampdf"),LineStyle(kDashed),LineColor(6));
	model.plotOn(frame,Name("bkgsum"),Components("bkgsum"),LineStyle(kSolid),LineColor(1));
	//hdatapdf.plotOn(frame,LineStyle(kSolid),LineColor(kRed),LineWidth(2));
	
	TCanvas* b1 = new TCanvas("b1","bkgsum fraction",800,400);
	Hfbkgsum_bin->GetXaxis()->SetTitle("M(3#pi) [MeV]");
	Hfbkgsum_bin->GetYaxis()->SetTitle("fraction");	
	Hfbkgsum_bin->GetYaxis()->SetTitle(TString::Format("fraction/%0.1f [MeV]",binwidth_temp));
   
	Hfbkgsum_binCL=Hfbkgsum_bin->Clone();
	Hfbkgsum_bin->SetFillColor(7);
   Hfbkgsum_bin->Draw("e4");
   Hfbkgsum_binCL->Draw("histo p same");
   
   legb1 = new TLegend(0.54,0.4,0.88,0.85);
	legb1->SetFillStyle(0); 
	legb1->SetBorderSize(0);  
	legb1->SetNColumns(1);
	
	legb1->AddEntry(Hfbkgsum_binCL,"f_{bkgsum}","l");
	legb1->SetTextFont(132);
	legb1->Draw("Same");
	legtextsize(legb1, 0.06);
   
   TCanvas* b2 = new TCanvas("b2","bkgsum number",800,400);
   HNbkgsum_bin->GetXaxis()->SetTitle("M(3#pi) [MeV]");
   HNbkgsum_bin->GetYaxis()->SetTitle(TString::Format("Entries/%0.1f [MeV]",binwidth_temp));
   HNbkgsum_binCL=HNbkgsum_bin->Clone();
   HNbkgsum_bin->SetFillColor(7); // or any other color
	HNbkgsum_bin->Draw("e4");
	HNbkgsum_binCL->Draw("histo p same");
   
   TCanvas* b3 = new TCanvas("b3","omegam candidates",800,400);
   TLine *l = new TLine(xmin_IM,0.0,xmax_IM,0.0); format_l(l,2,2,2);
   HNsig_bin->GetXaxis()->SetTitle("M(3#pi) [MeV]");
	HNsig_bin->GetYaxis()->SetTitle(TString::Format("Entries/%0.1f [MeV]",binwidth_temp));	
   HNsig_bin->Draw();
   l->Draw("Same");
   
   legb3 = new TLegend(0.64,0.4,0.88,0.85);
	legb3->SetFillStyle(0); 
	legb3->SetBorderSize(0);  
	legb3->SetNColumns(1);
	
	legb3->AddEntry(HNsig_bin,"#omega#gamma candidates","l");
	legb3->SetTextFont(132);
	legb3->Draw("Same");
	legtextsize(legb3, 0.06); //hhomegamgen
	
	TCanvas* b4 = new TCanvas("b4","generated omegam (MC true)",800,400);
   hhomegamgen->Draw("histo");
   
   TCanvas* b5 = new TCanvas("b5","omegam reconstructed after all cuts)",800,400);
   hhomegam->Draw("histo"); 
   
   TCanvas* b6 = new TCanvas("b6","omegam effeciency",800,400);
   Heffcy_bin->Draw();
	
	TCanvas* c = new TCanvas("IMfit","IMfit",800,400);
	frame->GetXaxis()->SetTitle("M(3#pi) [MeV]");	
	frame->GetYaxis()->SetTitle(TString::Format("Entries/%0.1f [MeV]",binwidth_temp));
	c->Divide(1); 
   c->cd(1); 
   frame->Draw();
   hhdata->SetMarkerStyle(kFullCircle);
   legc1 = new TLegend(0.64,0.6,0.88,0.9);
	legc1->SetFillStyle(0); 
	legc1->SetBorderSize(0);  
	legc1->SetNColumns(2);
	
	legc1->AddEntry(hhdata,"data","lp");
	legc1->AddEntry("model","fit","l");
	legc1->AddEntry("sig","#omega#gamma","l");
	legc1->AddEntry("bkgsum","bkg sum","l");
	legc1->AddEntry("omegpipdf","#omega#pi^{0}","l");
	legc1->AddEntry("threepigampdf","bkg rest","l");
	legc1->SetTextFont(132);
	legc1->Draw("Same");
	legtextsize(legc1, 0.05);
	
	
	
   Double_t chi2 = frame->chiSquare(3);
   std::cout<<"chi2 value = "<<chi2<<", ndf = "<<3<<endl;
}
