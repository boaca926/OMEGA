#include "Getname.C"
#include <iostream>
#include <string>


void format_l(TLine* line, Int_t color, Int_t width, Int_t style) {
	line->SetLineColor(color);
	line->SetLineWidth(width);
	line->SetLineStyle(style);
}

Double_t getyvalue(Double_t k, Double_t b, Double_t x) {
	Double_t y=0.;
	y=k*x+b; 
	
	return y;
}

Double_t getxvalue(Double_t k, Double_t b, Double_t y) {
	Double_t x=0.;
	x=(y-b)/k; 
	
	return x;
}

Double_t getkvalue(Double_t x0, Double_t y0, Double_t x1, Double_t y1) {
	Double_t k=0., yvalue=0.;
	k=(y1-y0)/(x1-x0); 
	
	return k;
}

Double_t getbvalue(Double_t k, Double_t x, Double_t x0, Double_t y0){
	Double_t b=0.;
	b=k*(x-x0)+y0;
	
	return b;
}


Double_t getcrossx(Double_t k1, Double_t k2, Double_t b1, Double_t b2) {
	Double_t x=0.;
	x=(b2-b1)/(k1-k2);
	return x;
}

Double_t getcrossy(Double_t k1, Double_t b1, Double_t xcross) {
	Double_t y=0.;
	y=k1*xcross+b1;
	return y;
}

void legtextsize(TLegend* l, Double_t size) {
  for(int i=0 ; i<l->GetListOfPrimitives()->GetSize() ; i++) {
    TLegendEntry *header = (TLegendEntry*)l->GetListOfPrimitives()->At(i);
    header->SetTextSize(size);
  }      
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
	
	if (!CUTTAG){
		TFile *f= new TFile("./ROOT/TREE_Pre.root");
	}
	else {
		TFile *f= new TFile("./ROOT/TREE_"+cutname[modpos]+".root");
	}	
	// define variables
	Double_t threepiIM = 0.;
	Double_t  chi2value = 0;
	Double_t bestPiTime = 0.;
	Double_t bestETime = 0.;
	Double_t deltaE = 0.;
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
	TString SBestPiTime = getbraname(5);
	TString SBestETime = getbraname(6);
	TString SDeltaE = getbraname(7);
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
		tree_temp->SetBranchAddress(SBestPiTime,&bestPiTime);
		tree_temp->SetBranchAddress(SBestETime,&bestETime);
		tree_temp->SetBranchAddress(SDeltaE,&deltaE);
	}
	// create a list of histo
	TH1D *HCHI2[NbTree];
	TH1D *HDeltaE[NbTree];
	TH2D *HTOF[NbTree];
	
	for (Int_t i=0;i<NbTree;i++) {
		HCHI2[i] = new TH1D("hChi2Value_"+gettreename(i),"Chi2 values",bin_IM,xmin_IM,xmax_IM); format_h(HCHI2[i],colorid[i],0,1);
		HTOF[i] = new TH2D("hToF_"+gettreename(i),"TOF",bin_TOF,xmin_TOF,xmax_TOF,bin_TOF,xmin_TOF,xmax_TOF);
		HDeltaE[i] = new TH1D("hDeltaE_"+gettreename(i),"DeltaE",bin_DeltaE,xmin_DeltaE,xmax_DeltaE);
}
	
	//
	for (Int_t irow=0;irow<TOMEGAPI->GetEntries();irow++) { // omega pi
   	TOMEGAPI->GetEntry(irow); 
   	HCHI2[0]->Fill(chi2value);
   	HTOF[0]->Fill(bestPiTime,bestETime);
   	HDeltaE[0]->Fill(deltaE);
   } 
   // 
   for (Int_t irow=0;irow<TKPM->GetEntries();irow++) { // kpm
   	TKPM->GetEntry(irow); 
   	HCHI2[1]->Fill(chi2value);
   	HTOF[1]->Fill(bestPiTime,bestETime);
   	HDeltaE[1]->Fill(deltaE);
   }
   // 
   for (Int_t irow=0;irow<TKSL->GetEntries();irow++) { // ksl
   	TKSL->GetEntry(irow); 
   	HCHI2[2]->Fill(chi2value);
   	HTOF[2]->Fill(bestPiTime,bestETime);
   }
   //
   for (Int_t irow=0;irow<TTHREEPIGAM->GetEntries();irow++) { // threepi gamma
   	TTHREEPIGAM->GetEntry(irow); 
   	HCHI2[3]->Fill(chi2value);
   	HTOF[3]->Fill(bestPiTime,bestETime);
   	HDeltaE[3]->Fill(deltaE);
   }
   //
   for (Int_t irow=0;irow<TTHREEPI->GetEntries();irow++) { // threepi 
   	TTHREEPI->GetEntry(irow); 
   	HCHI2[4]->Fill(chi2value);
   	HTOF[4]->Fill(bestPiTime,bestETime);
   	HDeltaE[4]->Fill(deltaE);
   }
   //
   for (Int_t irow=0;irow<TETAGAM->GetEntries();irow++) { // threepi 
   	TETAGAM->GetEntry(irow); 
   	HCHI2[5]->Fill(chi2value);
   	HTOF[5]->Fill(bestPiTime,bestETime);
   	HDeltaE[5]->Fill(deltaE);
   }
   //
   for (Int_t irow=0;irow<TBKGSUM1->GetEntries();irow++) { // threepi 
   	TBKGSUM1->GetEntry(irow); 
   	HCHI2[6]->Fill(chi2value);
   	HTOF[6]->Fill(bestPiTime,bestETime);
   	HDeltaE[6]->Fill(deltaE);
   }
   //
   for (Int_t irow=0;irow<TBKGSUM2->GetEntries();irow++) { // threepi 
   	TBKGSUM2->GetEntry(irow); 
   	HCHI2[7]->Fill(chi2value);
   	HTOF[7]->Fill(bestPiTime,bestETime);
   	HDeltaE[7]->Fill(deltaE);
   }
   //
   for (Int_t irow=0;irow<TMCSUM->GetEntries();irow++) { // threepi 
   	TMCSUM->GetEntry(irow); 
   	HCHI2[8]->Fill(chi2value);
   	HTOF[8]->Fill(bestPiTime,bestETime);
   	HDeltaE[8]->Fill(deltaE);
   }
   //
   for (Int_t irow=0;irow<TEEG->GetEntries();irow++) { // threepi 
   	TEEG->GetEntry(irow); 
   	HCHI2[9]->Fill(chi2value);
   	HTOF[9]->Fill(bestPiTime,bestETime);
   	HDeltaE[9]->Fill(deltaE);
   }
   //
   for (Int_t irow=0;irow<TDATA->GetEntries();irow++) { // threepi 
   	TDATA->GetEntry(irow); 
   	HCHI2[10]->Fill(chi2value);
   	HTOF[10]->Fill(bestPiTime,bestETime);
   	HDeltaE[10]->Fill(deltaE);
   }
   HCHI2[10]->SetMarkerStyle(2);
   
   TFile hf("./ROOT/HISTOS.root","recreate");
   for (Int_t i=0;i<NbTree;i++) {
		HCHI2[i]->Write();
		HTOF[i]->Write();
		HDeltaE[i]->Write();
	}

}
