#include "Getname.C"
#include <iostream>
#include <string>
#include "gethisto.C"

void IMplot() {
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
	TH1D *hThreepiIM_OMEGAPI = (TH1D*)f->Get("hIM_"+OMEGAPI); 
	TH1D *hThreepiIM_KPM = (TH1D*)f->Get("hIM_"+KPM); 	
	TH1D *hThreepiIM_KSL = (TH1D*)f->Get("hIM_"+KSL); 
	TH1D *hThreepiIM_THREEPIGAM = (TH1D*)f->Get("hIM_"+THREEPIGAM); 
	TH1D *hThreepiIM_THREEPI = (TH1D*)f->Get("hIM_"+THREEPI);
	TH1D *hThreepiIM_ETAGAM = (TH1D*)f->Get("hIM_"+ETAGAM); 
	TH1D *hThreepiIM_BKGSUM1 = (TH1D*)f->Get("hIM_"+BKGSUM1); 
	TH1D *hThreepiIM_BKGSUM2 = (TH1D*)f->Get("hIM_"+BKGSUM2); 
	TH1D *hThreepiIM_MCSUM = (TH1D*)f->Get("hIM_"+MCSUM); 
	TH1D *hThreepiIM_EEG = (TH1D*)f->Get("hIM_"+EEG); 
	TH1D *hThreepiIM_DATA = (TH1D*)f->Get("hIM_"+DATA); 
	// add to TList
	TCollection* histlist = new TList;
	histlist->Add(hThreepiIM_OMEGAPI);
	histlist->Add(hThreepiIM_KPM);
	histlist->Add(hThreepiIM_KSL);
	histlist->Add(hThreepiIM_THREEPIGAM);
	histlist->Add(hThreepiIM_THREEPI);
	histlist->Add(hThreepiIM_ETAGAM);
	histlist->Add(hThreepiIM_BKGSUM1);
	histlist->Add(hThreepiIM_BKGSUM2);
	histlist->Add(hThreepiIM_MCSUM);
	histlist->Add(hThreepiIM_EEG);
	histlist->Add(hThreepiIM_DATA);
	
	/// plots of unfitted histos
	TCanvas *c = new TCanvas("Chi2Distr","Chi2 Distr.",700,700);
	c->Divide(1,1);
	
	c->cd(1);
	Double_t ymax = hThreepiIM_DATA->GetMaximum();
	Double_t widthc1=getbinwidth(hThreepiIM_OMEGAPI);
	hThreepiIM_DATA->GetYaxis()->SetTitle(TString::Format("Entries/%0.1f",widthc1));
	hThreepiIM_DATA->GetXaxis()->SetTitle("M(3#pi) MeV");
	hThreepiIM_DATA->GetXaxis()->SetRangeUser(400.,1500.);
	//hThreepiIM_DATA->GetYaxis()->SetRangeUser(1.,ymax*1.2);
	hThreepiIM_DATA->GetYaxis()->SetTitleOffset(1.4);
	hThreepiIM_DATA->Draw("e1"); 
	hThreepiIM_OMEGAPI->Draw("Same");
	hThreepiIM_KPM->Draw("Same"); 	
	hThreepiIM_KSL->Draw("Same");
	hThreepiIM_THREEPIGAM->Draw("Same"); 
	hThreepiIM_THREEPI->Draw("Same");
	hThreepiIM_ETAGAM->Draw("Same"); 
	hThreepiIM_BKGSUM1->Draw("Same");	
	hThreepiIM_EEG->Draw("Same");
	//hThreepiIM_DATA->Draw("Samee1");
	hThreepiIM_MCSUM->Draw("Same"); 
	
	legc1 = new TLegend(0.54,0.4,0.88,0.85);
	legc1->SetFillStyle(0); 
	legc1->SetBorderSize(0);  
	legc1->SetNColumns(2);
	
	legc1->AddEntry(hThreepiIM_OMEGAPI,"#omega#pi^{0}","l");
	legc1->AddEntry(hThreepiIM_KSL,"KSKL","l");
	legc1->AddEntry(hThreepiIM_KPM,"KPM","l");
	legc1->AddEntry(hThreepiIM_THREEPIGAM,"#pi^{+}#pi^{-}#pi^{0}#gamma","l");
	legc1->AddEntry(hThreepiIM_THREEPI,"#pi^{+}#pi^{-}#pi^{0}","l");
	legc1->AddEntry(hThreepiIM_ETAGAM,"#eta#gamma","l");
	legc1->AddEntry(hThreepiIM_EEG,"e^{+}e^{-}#gamma","l");
	legc1->AddEntry(hThreepiIM_BKGSUM1,"MC rest","l");
	legc1->AddEntry(hThreepiIM_DATA,"Data","l");	
	legc1->AddEntry(hThreepiIM_MCSUM,"ALLCHAIN","l");
	legc1->SetTextFont(132);
	legc1->Draw("Same");
	legtextsize(legc1, 0.03);
	
}
