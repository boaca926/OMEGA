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
	Double_t threepiIM_MC = 0.;
	Double_t chi2value = 0;
	Double_t bestPiTime = 0.;
	Double_t bestETime = 0.;
	Double_t deltaE = 0.;
	Double_t tracksum = 0.;
	Double_t threepiIM = 0.;
	Double_t Emaxprompt = 0.;
	Double_t bestpiphoton1Ekinfit = 0.;
	Double_t bestpiphoton2Ekinfit = 0.;
	Double_t pionphotonEsum = 0.;
	Double_t pi0IM = 0.;
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
	TString STracksum = getbraname(8); 
	TString SThreepiIM = getbraname(9); 
	TString SEmaxprompt = getbraname(12);
	TString SBestpiphoton1Ekinfit = getbraname(13);
	TString SBestpiphoton2Ekinfit = getbraname(14);
	TString SPionphotonEsum = getbraname(17);
	TString SPi0IM = getbraname(20);
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
		tree_temp->SetBranchAddress(STracksum,&tracksum);
		tree_temp->SetBranchAddress(SThreepiIM,&threepiIM);
		tree_temp->SetBranchAddress(SEmaxprompt,&Emaxprompt);
		tree_temp->SetBranchAddress(SBestpiphoton1Ekinfit,&bestpiphoton1Ekinfit);
		tree_temp->SetBranchAddress(SBestpiphoton2Ekinfit,&bestpiphoton2Ekinfit);
		tree_temp->SetBranchAddress(SPionphotonEsum,&pionphotonEsum);
		tree_temp->SetBranchAddress(SPi0IM,&pi0IM);
	}
	// create a list of histo
	TH1D *HEMAX[NbTree];
	TH1D *HIM[NbTree];
	TH1D *HCHI2[NbTree];
	TH1D *HDeltaE[NbTree];
	TH1D *HTracksum[NbTree];
	TH2D *HTOF[NbTree];
	TH2D *HScatter1[NbTree];
	TH2D *HScatter2[NbTree];
	TH1D *HPi0IM[NbTree];
	
	for (Int_t i=0;i<NbTree;i++) {
		HEMAX[i] = new TH1D("HEMAX_"+gettreename(i),"Maximum energy of prompt photon",bin,xmin,xmax); format_h(HEMAX[i],colorid[i],0,1);
		HIM[i] = new TH1D("hIM_"+gettreename(i),"Invariant mass",bin_IM,xmin_IM,xmax_IM); format_h(HIM[i],colorid[i],0,1);
		HCHI2[i] = new TH1D("hChi2Value_"+gettreename(i),"Chi2 values",bin_Chi2,xmin_Chi2,xmax_Chi2); format_h(HCHI2[i],colorid[i],0,1);
		HTOF[i] = new TH2D("hToF_"+gettreename(i),"TOF",bin_TOF,xmin_TOF,xmax_TOF,bin_TOF,xmin_TOF,xmax_TOF);
		HDeltaE[i] = new TH1D("hDeltaE_"+gettreename(i),"DeltaE",bin_DeltaE,xmin_DeltaE,xmax_DeltaE);
		HTracksum[i] = new TH1D("hTracksum_"+gettreename(i),"Tracksum",bin_Tracksum,xmin_Tracksum,xmax_Tracksum);
		HScatter1[i] = new TH2D("HScatter1_"+gettreename(i),"Tracksum vs DeltaE",bin_Tracksum,xmin_Tracksum,xmax_Tracksum,bin_DeltaE,xmin_DeltaE,xmax_DeltaE);
		HScatter2[i] = new TH2D("HScatter2_"+gettreename(i),"sum of pio0 photon momenta  vs sum of charge track momenta",bin_pionPsum,xmin_pionPsum,xmax_pionPsum,bin_Tracksum,xmin_Tracksum,xmax_Tracksum);
		HPi0IM[i] = new TH1D("hPi0IM_"+gettreename(i),"Invariant mass of netral pion",bin_pi0IM,xmin_pi0IM,xmax_pi0IM); format_h(HPi0IM[i],colorid[i],0,1);
}
	
	//
	for (Int_t irow=0;irow<TOMEGAPI->GetEntries();irow++) { // omega pi
   	TOMEGAPI->GetEntry(irow); 
   	HCHI2[0]->Fill(chi2value);
   	HTOF[0]->Fill(bestPiTime,bestETime);
   	HDeltaE[0]->Fill(deltaE);
   	HScatter1[0]->Fill(tracksum,deltaE);
   	HScatter2[0]->Fill(pionphotonEsum,tracksum);
   	HIM[0]->Fill(threepiIM);
   	HEMAX[0]->Fill(Emaxprompt);
   	HPi0IM[0]->Fill(pi0IM);
   } 
   // 
   for (Int_t irow=0;irow<TKPM->GetEntries();irow++) { // kpm
   	TKPM->GetEntry(irow); 
   	HCHI2[1]->Fill(chi2value);
   	HTOF[1]->Fill(bestPiTime,bestETime);
   	HDeltaE[1]->Fill(deltaE);
   	HScatter1[1]->Fill(tracksum,deltaE);
   	HScatter2[1]->Fill(pionphotonEsum,tracksum);
   	HIM[1]->Fill(threepiIM);
   	HEMAX[1]->Fill(Emaxprompt);
   	HPi0IM[1]->Fill(pi0IM);
   }
   // 
   for (Int_t irow=0;irow<TKSL->GetEntries();irow++) { // ksl
   	TKSL->GetEntry(irow); 
   	HCHI2[2]->Fill(chi2value);
   	HTOF[2]->Fill(bestPiTime,bestETime);
   	HScatter1[2]->Fill(tracksum,deltaE);
   	HScatter2[2]->Fill(pionphotonEsum,tracksum);
   	HIM[2]->Fill(threepiIM);
   	HEMAX[2]->Fill(Emaxprompt);
   	HPi0IM[2]->Fill(pi0IM);
   }
   //
   for (Int_t irow=0;irow<TTHREEPIGAM->GetEntries();irow++) { // threepi gamma
   	TTHREEPIGAM->GetEntry(irow); 
   	HCHI2[3]->Fill(chi2value);
   	HTOF[3]->Fill(bestPiTime,bestETime);
   	HDeltaE[3]->Fill(deltaE);
   	HScatter1[3]->Fill(tracksum,deltaE);
   	HScatter2[3]->Fill(pionphotonEsum,tracksum);
   	HIM[3]->Fill(threepiIM);
   	HEMAX[3]->Fill(Emaxprompt);
   	HPi0IM[3]->Fill(pi0IM);
   }
   //
   for (Int_t irow=0;irow<TTHREEPI->GetEntries();irow++) { // threepi 
   	TTHREEPI->GetEntry(irow); 
   	HCHI2[4]->Fill(chi2value);
   	HTOF[4]->Fill(bestPiTime,bestETime);
   	HDeltaE[4]->Fill(deltaE);
   	HScatter1[4]->Fill(tracksum,deltaE);
   	HScatter2[4]->Fill(pionphotonEsum,tracksum);
   	HIM[4]->Fill(threepiIM);
   	HEMAX[4]->Fill(Emaxprompt);
   	HPi0IM[4]->Fill(pi0IM);
   }
   //
   for (Int_t irow=0;irow<TETAGAM->GetEntries();irow++) { // threepi 
   	TETAGAM->GetEntry(irow); 
   	HCHI2[5]->Fill(chi2value);
   	HTOF[5]->Fill(bestPiTime,bestETime);
   	HDeltaE[5]->Fill(deltaE);
   	HScatter1[5]->Fill(tracksum,deltaE);
   	HScatter2[5]->Fill(pionphotonEsum,tracksum);
   	HIM[5]->Fill(threepiIM);
   	HEMAX[5]->Fill(Emaxprompt);
   	HPi0IM[5]->Fill(pi0IM);
   }
   //
   for (Int_t irow=0;irow<TBKGSUM1->GetEntries();irow++) { // threepi 
   	TBKGSUM1->GetEntry(irow); 
   	HCHI2[6]->Fill(chi2value);
   	HTOF[6]->Fill(bestPiTime,bestETime);
   	HDeltaE[6]->Fill(deltaE);
   	HScatter1[6]->Fill(tracksum,deltaE);
   	HScatter2[6]->Fill(pionphotonEsum,tracksum);
		HIM[6]->Fill(threepiIM);
		HEMAX[6]->Fill(Emaxprompt);
		HPi0IM[6]->Fill(pi0IM);
   }
   //
   for (Int_t irow=0;irow<TBKGSUM2->GetEntries();irow++) { // threepi 
   	TBKGSUM2->GetEntry(irow); 
   	HCHI2[7]->Fill(chi2value);
   	HTOF[7]->Fill(bestPiTime,bestETime);
   	HDeltaE[7]->Fill(deltaE);
   	HScatter1[7]->Fill(tracksum,deltaE);
   	HScatter2[7]->Fill(pionphotonEsum,tracksum);
   	HIM[7]->Fill(threepiIM);
   	HEMAX[7]->Fill(Emaxprompt);
   	HPi0IM[7]->Fill(pi0IM);
   }
   //
   for (Int_t irow=0;irow<TMCSUM->GetEntries();irow++) { // threepi 
   	TMCSUM->GetEntry(irow); 
   	HCHI2[8]->Fill(chi2value);
   	HTOF[8]->Fill(bestPiTime,bestETime);
   	HDeltaE[8]->Fill(deltaE);
   	HScatter1[8]->Fill(tracksum,deltaE);
   	HScatter2[8]->Fill(pionphotonEsum,tracksum);
   	HIM[8]->Fill(threepiIM);
   	HEMAX[8]->Fill(Emaxprompt);
   	HPi0IM[8]->Fill(pi0IM);
   }
   //
   for (Int_t irow=0;irow<TEEG->GetEntries();irow++) { // threepi 
   	TEEG->GetEntry(irow); 
   	HCHI2[9]->Fill(chi2value);
   	HTOF[9]->Fill(bestPiTime,bestETime);
   	HDeltaE[9]->Fill(deltaE);
   	HScatter1[9]->Fill(tracksum,deltaE);
   	HScatter2[9]->Fill(pionphotonEsum,tracksum);
   	HIM[9]->Fill(threepiIM);
   	HEMAX[9]->Fill(Emaxprompt);
   	HPi0IM[9]->Fill(pi0IM);
   }
   //
   for (Int_t irow=0;irow<TDATA->GetEntries();irow++) { // threepi 
   	TDATA->GetEntry(irow); 
   	HCHI2[10]->Fill(chi2value);
   	HTOF[10]->Fill(bestPiTime,bestETime);
   	HDeltaE[10]->Fill(deltaE);
   	HScatter1[10]->Fill(tracksum,deltaE);
   	HScatter2[10]->Fill(pionphotonEsum,tracksum);
   	HIM[10]->Fill(threepiIM);
   	HEMAX[10]->Fill(Emaxprompt);
   	HPi0IM[10]->Fill(pi0IM);
   }
   HCHI2[10]->SetMarkerStyle(2);
   HScatter2[10]->Fill(pionphotonEsum,tracksum);
   HIM[10]->SetMarkerStyle(2);
   HEMAX[10]->SetMarkerStyle(2);
   HPi0IM[10]->SetMarkerStyle(2);
   
   TFile hf("./ROOT/HISTOS.root","recreate");
   for (Int_t i=0;i<NbTree;i++) {
		HCHI2[i]->Write();
		HTOF[i]->Write();
		HDeltaE[i]->Write();
		HScatter1[i]->Write();
		HScatter2[i]->Write();
		HIM[i]->Write();
		HEMAX[i]->Write();
		HPi0IM[i]->Write();
	}

}
