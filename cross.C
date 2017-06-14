#include "Getname.C"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
#include "gethisto.C"

gSystem->Load("libRooFit");
using namespace std;
using namespace RooFit;

void cross(RooDataHist* h, int bin) {
	TH1D* hhdata = h->createHistogram("ThreepiIM",bin);
	double binsize=hhdata->GetNbinsX();
	std::cout<<"binsize = "<<binsize<<endl;
	hhdata->Draw();
}

void cross() {
	Double_t threepiIM = 0.;
	TString SThreepiIM = getbraname(9);//  
	// get root file
	TFile *findFile = new TFile("./ROOT/TREE_cutted.root","READ");
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
	
	// declear variable
	RooRealVar x("ThreepiIM","ThreepiIM",xmin_IM,xmax_IM);
	const int binnb=10;
	x.setBins(binnb);
	
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
  // RooRealVar fomegam("fomegam","fomegam fraction",fomegam_init);
   RooRealVar fmcrest("fmcrest","mcrest fraction",fmcrest_init);
   RooRealVar fthreepigam("fthreepigam","threepigam fraction",fthreepigam_init);
   RooRealVar sigfrac("sigfrac","signal fraction",fomegam_init);
   RooAddPdf sig("sig","Signal",omegampdf,sigfrac);
   RooAddPdf bkgsum("bkgsum","bkgsum",RooArgList(omegpipdf,threepigampdf),RooArgList(fomegpi,fthreepigam));
   //RooAddPdf model("model","model",RooArgList(sig,bkgsum),fomegam);
   //RooAddPdf sig("sig","Signal",omegampdf,sigfrac) ;
   RooRealVar nsig("nsig","signal fraction",10000,0.,100000.) ;
	RooRealVar nbkgsum("nbkgsum","background fraction",10000,0.,100000.) ;
	//RooAddPdf model("model","model",RooArgList(sig,bkgsum),RooArgList(nsig,nbkgsum));
	RooAddPdf model("model","model",RooArgList(sig,bkgsum),sigfrac);
	// fit
   //RooFitResult* rf = model.fitTo(data,Extended(kTRUE));
   RooFitResult* rf = model.fitTo(data);
   model.Print("t");
   // cross section
   // loop over all bins in data and test errors
   double nbdata = 0, binsize = 0, entries = 0, errdata = 0;
   double xlow = 0, xupp = 0, nbbkg = 0;
   // check bin size of the data histo
   TAxis* axis = hhdata->GetXaxis();
   binsize = hhdata->GetNbinsX();
   entries=getentriesfit(hhdata);
   std::cout<<"<<<<<<<<<<<<< bin size = "<<binsize<<" <<<<<<<<<<<<<<"<<endl;
   std::cout<<"total # data = "<<entries<<endl;
   for (int i = 1;i<=1; i++) {
   	cout<<i<<endl;
   	// get bin content from data histo
   	nbdata = hhdata->GetBinContent(i);
   	errdata = hhdata->GetBinError(i);
   	//std::cout<<"data bin content = "<<nbdata<<endl;
   	//std::cout<<"data bin error = "<<errdata<<endl;
   	// calculate bkg content
   	xlow = axis->GetBinLowEdge(i);
		xupp = axis->GetBinUpEdge(i);
		x.setRange("intrange",xlow,xupp) ;
		RooAbsReal* fracBkgRange_bin = bkgsum.createIntegral(x,x,"intrange");
		nbbkg = (N_d-N_omegpi-N_omegam)*fracBkgRange_bin->getVal();
		std::cout<<"integrate range "<<"["<<xlow<<", "<<xupp<<"]"<<endl;
		cout<<nbbkg<<endl;
   }
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
	
	TCanvas* c = new TCanvas("IMfit","IMfit",800,400);
	c->Divide(1) ;
   c->cd(1); 
   frame->Draw();
   
   legc1 = new TLegend(0.64,0.4,0.88,0.85);
	legc1->SetFillStyle(0); 
	legc1->SetBorderSize(0);  
	legc1->SetNColumns(1);
	
	legc1->AddEntry("data","data","LP");
	legc1->AddEntry("model","fit","l");
	legc1->AddEntry("sig","#omega#gamma (signal)","L");
	legc1->AddEntry("bkgsum","bkg sum","L");
	legc1->SetTextFont(132);
	legc1->Draw("Same");
	legtextsize(legc1, 0.05);
	
	
   Double_t chi2 = frame->chiSquare(3);
   std::cout<<"chi2 value = "<<chi2<<", ndf = "<<3<<endl;
}
