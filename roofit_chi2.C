#include "Getname.C"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"

gSystem->Load("libRooFit");
using namespace std;
using namespace RooFit;

void roofit_chi2() {
	Double_t threepiIM = 0.;
	TString SThreepiIM = getbraname(9); 
	// get root file
	TFile *findFile = new TFile("./ROOT/TREE_cutted.root","READ");
	// get tree name
	TString Data = gettreename(10);// data
	TString Sig = gettreename(3);// omega gamma
	TString Bkg1 = gettreename(0);// omega pi0
	TString Bkg2 = gettreename(2);// KSL
	TString Bkg3 = gettreename(7);// bkgsum2
	// declear variable
	RooRealVar x("ThreepiIM","ThreepiIM",xmin_IM,xmax_IM);
	const int binnb=10;
	x.setBins(binnb);
	//double scale=1.0/fsig;
	// get MC & DATA sample
	TTree *TData = (TTree*)findFile->Get("T"+Data+"_Pre"); // data
	double N_d=0;
   for (Int_t irow=0;irow<TData->GetEntries();irow++) {
   	N_d++;
   }
   std::cout<<"N_d = "<<N_d<<endl;	
   // sig
	TTree *TThreePiGam = (TTree*)findFile->Get("T"+Sig+"_Pre"); // signal omega gamma
	double N_s=0;
	double f0_init=0;
   for (Int_t irow=0;irow<TThreePiGam->GetEntries();irow++) {
   	N_s++;
   }
   f0_init=N_s/N_d;
   std::cout<<"N_s = "<<N_s<<endl;
   td::cout<<"f0_init = "<<f0_init<<endl;
   //
	TTree *TOmegaPi = (TTree*)findFile->Get("T"+Bkg1+"_Pre"); // bkg1 omega pi0
	double N_bkg1=0;
	double f1_init=0;
   for (Int_t irow=0;irow<TOmegaPi->GetEntries();irow++) {
   	N_bkg1++;
   }
   f1_init=(N_bkg1/N_d)*5.7/8;
   std::cout<<"N_bkg1 = "<<N_bkg1<<endl;
   td::cout<<"f1_init = "<<f1_init<<endl;
	// data
	RooDataSet data("data","data",RooArgSet(x),Import(*TData));
	RooDataHist* hdata = data.binnedClone();
	
}
