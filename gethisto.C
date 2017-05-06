#include "Getname.C"
#include <iostream>
#include <string>
void format_h(TH1D* h, Int_t fillcolor, Int_t fillstyle, Int_t width) {
	h->SetLineWidth(width);
	h->SetFillStyle(fillstyle);
	h->SetLineColor(fillcolor);
}

void gethisto() {
   gStyle->SetOptTitle(0);
   gStyle->SetStatBorderSize(0);
   gStyle->SetOptStat(0);
   gStyle->SetLineScalePS(2);
	TGaxis::SetMaxDigits(3);
	
	TFile *f= new TFile("./ROOT/TREE.root");
	// define variables
	Double_t threepiIM = 0., chi2value = 0;
	// get trees names and branch names
	TString OMEGAPI = gettreename(0); 
	TString KPM = gettreename(1);
	TString KSL = gettreename(2); //
	TString THREEPIGAM = gettreename(3); //
	TString THREEPI = gettreename(4); //
	TString ETAGAM = gettreename(5); //
	TString BKGSUM1 = gettreename(6); //
	TString BKGSUM2 = gettreename(7); //
	TString MCSUM = gettreename(8);
	TString EEG = gettreename(9); //std::cout<<EEG<<endl;
	TString DATA = gettreename(10); std::cout<<DATA<<endl;
	
	TString SIMthreepi = getbraname(1);
	TString Schi2value = getbraname(3);
	// get trees
	TTree *TOMEGAPI = (TTree*)f->Get("T"+OMEGAPI+"_Pre");
	TTree *TKPM = (TTree*)f->Get("T"+KPM+"_Pre");
	TTree *TKSL = (TTree*)f->Get("T"+KSL+"_Pre");
	TTree *TTHREEPI = (TTree*)f->Get("T"+THREEPI+"_Pre");
	TTree *TTHREEPIGAM = (TTree*)f->Get("T"+THREEPIGAM+"_Pre");
	// add to TList
	TCollection* treelist = new TList;
	treelist->Add(TOMEGAPI);
	treelist->Add(TKPM);
	treelist->Add(TKSL);
	treelist->Add(TTHREEPIGAM);
	treelist->Add(TTHREEPI);	
	// set branch address	
	TObject* treeout=0;
	TIter treeliter(treelist);
	while((treeout=treeliter.Next()) !=0) {
		//treeout->Print();
		TTree* tree_temp=dynamic_cast<TTree*>(treeout);
		tree_temp->SetBranchAddress(Schi2value,&chi2value);
	}
	// create a list of histo
	TH1D *HCHI2[NbTree];
	for (Int_t i=0;i<NbTree;i++) {
		HCHI2[i] = new TH1D("hChi2Value"+gettreename(i),"Chi2 values",bin,xmin_IM,xmax_IM); format_h(HCHI2[i],colorid[i],0,1);
	}
	
	//
	for (Int_t irow=0;irow<TOMEGAPI->GetEntries();irow++) { // omega pi
   	TOMEGAPI->GetEntry(irow); 
   	HCHI2[0]->Fill(chi2value);
   } 
   // 
   for (Int_t irow=0;irow<TKPM->GetEntries();irow++) { // kpm
   	TKPM->GetEntry(irow); 
   	HCHI2[1]->Fill(chi2value);
   }
   // 
   for (Int_t irow=0;irow<TKSL->GetEntries();irow++) { // ksl
   	TKSL->GetEntry(irow); 
   	HCHI2[2]->Fill(chi2value);
   }
   //
   for (Int_t irow=0;irow<TTHREEPIGAM->GetEntries();irow++) { // threepi gamma
   	TTHREEPIGAM->GetEntry(irow); 
   	HCHI2[3]->Fill(chi2value);
   }
   //
   for (Int_t irow=0;irow<TTHREEPI->GetEntries();irow++) { // threepi 
   	TTHREEPI->GetEntry(irow); 
   	HCHI2[4]->Fill(chi2value);
   }
   
   TFile hf("./ROOT/HISTOS.root","recreate");
   for (Int_t i=0;i<NbTree;i++) {
		HCHI2[i]->Write();
	}

}
