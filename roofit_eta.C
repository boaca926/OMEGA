#include "Getname.C"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"

gSystem->Load("libRooFit");
using namespace std;
using namespace RooFit;

void roofit_eta() {
	// declear variable
	double threepiIM = 0.;
	// get trees names and branch names
	TString OMEGAPI = gettreename(0); 
	TString KSL = gettreename(2);
	TString ETAGAM = gettreename(5);
	TString DATA = gettreename(10);// data
	
	TString SThreepiIM = getbraname(9); 	
	//
	RooRealVar x("ThreepiIM","ThreepiIM",xmin_IM,xmax_IM);
	x.setBins(bin_fit);
	TFile *findFile = new TFile("./ROOT/TREE_cutted.root","READ");	
	
	// get MC & DATA sample
	TTree *TDATA = (TTree*)findFile->Get("T"+DATA+"_Pre"); // data
	TTree *TETAGAM = (TTree*)findFile->Get("T"+ETAGAM+"_Pre"); // etagam
	TTree *TKSL = (TTree*)findFile->Get("T"+KSL+"_Pre"); // ksl
	TTree *TOMEGAPI = (TTree*)findFile->Get("T"+OMEGAPI+"_Pre"); // omegapi
	// add to TList
	TCollection* treelist = new TList;
	treelist->Add(TDATA);
	treelist->Add(TETAGAM);
	treelist->Add(TKSL);
	treelist->Add(TOMEGAPI);
	// set branch address	
	TObject* treeout=0;
	TIter treeliter(treelist);
	while((treeout=treeliter.Next()) !=0) {
		//treeout->Print();
		TTree* tree_temp=dynamic_cast<TTree*>(treeout);
		tree_temp->SetBranchAddress(SThreepiIM,&threepiIM);
	}
	// 
	double N_d = 0;
   for (Int_t irow=0;irow<TDATA->GetEntries();irow++) { // data
   	TDATA->GetEntry(irow); 
   	if(threepiIM > xmin1_IM && threepiIM < xmax1_IM) {
   		N_d++;
   	}
   	
   }
   std::cout<<"N_d = "<<N_d<<endl;
   RooDataSet data("data","data",RooArgSet(x),Import(*TDATA));
   // Create a binned dataset with 20 bins and 500 events
   RooDataHist* hdata = data.binnedClone();
   // Represent data in dh as pdf in x
   RooHistPdf hdatapdf("hdatapdf","hdatapdf",x,*hdata,0);
   //
   double N_etagam = 0, f_etagam = 0;
   for (Int_t irow=0;irow<TETAGAM->GetEntries();irow++) { // data
   	TETAGAM->GetEntry(irow); 
   	if(threepiIM > xmin1_IM && threepiIM < xmax1_IM) {
   		N_etagam++;
   	}
   	
   }
   f_etagam = N_etagam/N_d;
   std::cout<<"N_etagam = "<<N_etagam<<", "<<"f_etagam = "<<f_etagam<<endl;
   RooDataSet etagam("etagam","etagam",RooArgSet(x),Import(*TETAGAM));
   RooKeysPdf etagampdf("etagampdf", "etagampdf", x, etagam, RooKeysPdf::MirrorBoth, 1);
   //
   double N_ksl = 0, f_ksl = 0;
   for (Int_t irow=0;irow<TKSL->GetEntries();irow++) { // data
   	TKSL->GetEntry(irow); 
   	if(threepiIM > xmin1_IM && threepiIM < xmax1_IM) {
   		N_ksl++;
   	}
   	
   }
   f_ksl = N_ksl/N_d;
   std::cout<<"N_ksl = "<<N_ksl<<", "<<"f_ksl = "<<f_ksl<<endl;
   RooDataSet ksl("ksl","ksl",RooArgSet(x),Import(*TKSL));
   RooKeysPdf kslpdf("kslpdf", "kslpdf", x, ksl, RooKeysPdf::MirrorBoth, 1);
   //
   double N_omegapi = 0, f_omegapi = 0;
   for (Int_t irow=0;irow<TOMEGAPI->GetEntries();irow++) { // data
   	TOMEGAPI->GetEntry(irow); 
   	if(threepiIM > xmin1_IM && threepiIM < xmax1_IM) {
   		N_omegapi++;
   	}
   	
   }
   f_omegapi = N_omegapi/N_d;
   std::cout<<"N_omegapi = "<<N_omegapi<<", "<<"f_omegapi = "<<f_omegapi<<endl;
   RooDataSet omegapi("omegapi","omegapi",RooArgSet(x),Import(*TOMEGAPI));
   RooKeysPdf omegapipdf("omegapipdf", "omegapipdf", x, omegapi, RooKeysPdf::MirrorBoth, 1);
   // get model
	RooRealVar kslfrac("kslfrac","kslfrac",f_ksl,0.,1.);
	RooRealVar omegapifrac("omegapifrac","omegapifrac",f_omegapi,0.,1.);
	RooRealVar etagamfrac("etagamfrac","etagamfrac",1-f_ksl-f_omegapi,0.,1.);
	RooAddPdf bkgsum("bkgsum","bkgsum",RooArgList(kslpdf,omegapipdf),RooArgList(kslfrac,omegapifrac));
	RooAddPdf model("model","model",RooArgList(etagampdf,bkgsum),etagamfrac);
	// fit
	RooFitResult* rf = model.fitTo(data,Range(xmin1_IM,xmax1_IM));
   // Draw all frames on a canvas
	RooPlot* frame = x.frame(); 
	//data.plotOn(frame); 
	hdatapdf.plotOn(frame,LineStyle(kSolid),LineColor(kBlack));
	model.plotOn(frame,LineStyle(kSolid),LineColor(kRed));
	//etagampdf.plotOn(frame,LineStyle(kSolid),LineColor(3));
	//kslpdf.plotOn(frame,LineStyle(kSolid),LineColor(15)); 
	//omegapipdf.plotOn(frame,LineStyle(kSolid),LineColor(7));
	//
	TCanvas* c = new TCanvas("IMfit","IMfit",800,400) ;
   c->Divide(1) ;
   c->cd(1); 
   gPad->SetLeftMargin(0.15); 
   //frame->GetXaxis()->SetRangeUser(xmin1_IM,xmax1_IM);
   frame->GetYaxis()->SetTitleOffset(1.6); 
   frame->Draw();
	
	
}
