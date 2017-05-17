#include "Getname.C"
#include <iostream>
#include <string>
#include "gethisto.C"

void scatt2plot() {
	gStyle->SetOptTitle(0);
   gStyle->SetStatBorderSize(0);
   gStyle->SetOptStat(0);
   gStyle->SetLineScalePS(2);
	TGaxis::SetMaxDigits(3);
	
	TFile *f= new TFile("./ROOT/HISTOS.root");
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
	TString DATA = gettreename(10);
	
	// get histos
	TH2D *HScatter2_OMEGAPI = (TH2D*)f->Get("HScatter2_"+OMEGAPI); 
	TH2D *HScatter2_KPM = (TH2D*)f->Get("HScatter2_"+KPM); 	
	TH2D *HScatter2_KSL = (TH2D*)f->Get("HScatter2_"+KSL); 
	TH2D *HScatter2_THREEPIGAM = (TH2D*)f->Get("HScatter2_"+THREEPIGAM); 
	TH2D *HScatter2_THREEPI = (TH2D*)f->Get("HScatter2_"+THREEPI);
	TH2D *HScatter2_ETAGAM = (TH2D*)f->Get("HScatter2_"+ETAGAM); 
	TH2D *HScatter2_BKGSUM1 = (TH2D*)f->Get("HScatter2_"+BKGSUM1); 
	TH2D *HScatter2_BKGSUM2 = (TH2D*)f->Get("HScatter2_"+BKGSUM2); 
	TH2D *HScatter2_MCSUM = (TH2D*)f->Get("HScatter2_"+MCSUM); 
	TH2D *HScatter2_EEG = (TH2D*)f->Get("HScatter2_"+EEG); 
	TH2D *HScatter2_DATA = (TH2D*)f->Get("HScatter2_"+DATA);
	
	// add to TList
	TCollection* histlist = new TList;
	histlist->Add(HScatter2_OMEGAPI);
	histlist->Add(HScatter2_KPM);
	histlist->Add(HScatter2_KSL);
	histlist->Add(HScatter2_THREEPIGAM);
	histlist->Add(HScatter2_THREEPI);
	histlist->Add(HScatter2_ETAGAM);
	histlist->Add(HScatter2_BKGSUM1);
	histlist->Add(HScatter2_BKGSUM2);
	histlist->Add(HScatter2_MCSUM);
	histlist->Add(HScatter2_EEG);
	histlist->Add(HScatter2_DATA);
	
	TCanvas *c = new TCanvas("c","pion photon momenta sum vs track momenta sum ",700,700);
	c->Divide(2,1);
	TLine *l_cut = new TLine(xmin_Tracksum,deltaEcut,xmax_Tracksum,deltaEcut); format_l(l_cut,4,1,1);
	TLine *l1_cut = new TLine(xmin_Tracksum,deltaEcut+cutstep_std[3],xmax_Tracksum,deltaEcut+cutstep_std[3]); format_l(l1_cut,2,1,1);
	TLine *l2_cut = new TLine(xmin_Tracksum,deltaEcut-cutstep_std[3],xmax_Tracksum,deltaEcut-cutstep_std[3]); format_l(l2_cut,1,1,1);
	c->cd(1);
	HScatter2_MCSUM->GetXaxis()->SetTitle("P_{#Sigma_{1,2}}");
	HScatter2_MCSUM->GetYaxis()->SetTitle("P_{#Sigma_{#pm}}");
	HScatter2_MCSUM->GetYaxis()->SetTitleOffset(1.4);
	HScatter2_MCSUM->Draw("COLZ");

	gPad->SetLogz();
	
	c->cd(2);
	HScatter2_DATA->GetXaxis()->SetTitle("P_{#Sigma_{1,2}}");
	HScatter2_DATA->GetYaxis()->SetTitle("P_{#Sigma_{#pm}}");
	HScatter2_DATA->GetYaxis()->SetTitleOffset(1.4);
	HScatter2_DATA->Draw("COLZ");
	l_cut->Draw("Same");
	l1_cut->Draw("Same");
	l2_cut->Draw("Same");
	gPad->SetLogz();
	
	
	
	
}	
