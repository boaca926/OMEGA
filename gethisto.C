#include "Getname.C"
#include <iostream>
#include <string>

void drawline(Double_t a, Double_t b, Double_t c, Double_t d, Int_t color) {
	TLine *l = new TLine(a,b,c,d);
	l->SetLineColor(color);
	l->SetLineWidth(2);
	l->SetLineStyle(3); // 1=solid, 2=dash, 3=dash-dot, 4=dot-dot
	l->Draw("Same");
}

void legtextsize(TLegend* l, Double_t size) {
  for(int i=0 ; i<l->GetListOfPrimitives()->GetSize() ; i++) {
    TLegendEntry *header = (TLegendEntry*)l->GetListOfPrimitives()->At(i);
    header->SetTextSize(size);
  }      
}

void format_h(TH1D* h, Int_t fillcolor, Int_t fillstyle, Int_t width) {
	h->SetLineWidth(width);
	h->SetFillStyle(fillstyle);
	h->SetLineColor(fillcolor);
}


void drawline(Double_t a, Double_t b, Double_t c, Double_t d, Int_t color) {
	TLine *l = new TLine(a,b,c,d);
	l->SetLineColor(color);
	l->SetLineWidth(2);
	l->SetLineStyle(3); // 1=solid, 2=dash, 3=dash-dot, 4=dot-dot
	l->Draw("Same");
}

void legtextsize(TLegend* l, Double_t size) {
  for(int i=0 ; i<l->GetListOfPrimitives()->GetSize() ; i++) {
    TLegendEntry *header = (TLegendEntry*)l->GetListOfPrimitives()->At(i);
    header->SetTextSize(size);
  }      
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
	TTree *TETAGAM = (TTree*)f->Get("T"+ETAGAM+"_Pre");
	TTree *TBKGSUM1 = (TTree*)f->Get("T"+BKGSUM1+"_Pre");
	TTree *TBKGSUM2 = (TTree*)f->Get("T"+BKGSUM2+"_Pre");
	TTree *TMCSUM = (TTree*)f->Get("T"+MCSUM+"_Pre");
	TTree *TEEG = (TTree*)f->Get("T"+EEG+"_Pre");
	TTree *TDATA = (TTree*)f->Get("T"+DATA+"_Pre");
	// add to TList
	TCollection* treelist = new TList;
	treelist->Add(TOMEGAPI);
	treelist->Add(TKPM);
	treelist->Add(TKSL);
	treelist->Add(TTHREEPIGAM);
	treelist->Add(TTHREEPI);	
	treelist->Add(TETAGAM);	
	treelist->Add(TBKGSUM1);	
	treelist->Add(TBKGSUM2);
	treelist->Add(TMCSUM);
	treelist->Add(TEEG);
	treelist->Add(TDATA);
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
   //
   for (Int_t irow=0;irow<TETAGAM->GetEntries();irow++) { // threepi 
   	TETAGAM->GetEntry(irow); 
   	HCHI2[5]->Fill(chi2value);
   }
   //
   for (Int_t irow=0;irow<TBKGSUM1->GetEntries();irow++) { // threepi 
   	TBKGSUM1->GetEntry(irow); 
   	HCHI2[6]->Fill(chi2value);
   }
   //
   for (Int_t irow=0;irow<TBKGSUM2->GetEntries();irow++) { // threepi 
   	TBKGSUM2->GetEntry(irow); 
   	HCHI2[7]->Fill(chi2value);
   }
   //
   for (Int_t irow=0;irow<TMCSUM->GetEntries();irow++) { // threepi 
   	TMCSUM->GetEntry(irow); 
   	HCHI2[8]->Fill(chi2value);
   }
   //
   for (Int_t irow=0;irow<TEEG->GetEntries();irow++) { // threepi 
   	TEEG->GetEntry(irow); 
   	HCHI2[9]->Fill(chi2value);
   }
   //
   for (Int_t irow=0;irow<TDATA->GetEntries();irow++) { // threepi 
   	TDATA->GetEntry(irow); 
   	HCHI2[10]->Fill(chi2value);
   }
   HCHI2[10]->SetMarkerStyle(2);
   
   TFile hf("./ROOT/HISTOS.root","recreate");
   for (Int_t i=0;i<NbTree;i++) {
		HCHI2[i]->Write();
	}

}
