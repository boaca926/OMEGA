#include "Getname.C"
#include <iostream>
#include <string>
#include "gethisto.C"

void pi0IMplot() {
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
	TH1D *hPi0IM_OMEGAPI = (TH1D*)f->Get("HPi0IM_"+OMEGAPI); 
	TH1D *hPi0IM_KPM = (TH1D*)f->Get("HPi0IM_"+KPM); 	
	TH1D *hPi0IM_KSL = (TH1D*)f->Get("HPi0IM_"+KSL); 
	TH1D *hPi0IM_THREEPIGAM = (TH1D*)f->Get("HPi0IM_"+THREEPIGAM); 
	TH1D *hPi0IM_THREEPI = (TH1D*)f->Get("HPi0IM_"+THREEPI);
	TH1D *hPi0IM_ETAGAM = (TH1D*)f->Get("HPi0IM_"+ETAGAM); 
	TH1D *hPi0IM_BKGSUM1 = (TH1D*)f->Get("HPi0IM_"+BKGSUM1); 
	TH1D *hPi0IM_BKGSUM2 = (TH1D*)f->Get("HPi0IM_"+BKGSUM2); 
	TH1D *hPi0IM_MCSUM = (TH1D*)f->Get("HPi0IM_"+MCSUM); 
	TH1D *hPi0IM_EEG = (TH1D*)f->Get("HPi0IM_"+EEG); 
	TH1D *hPi0IM_DATA = (TH1D*)f->Get("HPi0IM_"+DATA); 
	
	/// plots of unfitted histos
	TCanvas *c = new TCanvas("Chi2Distr","Chi2 Distr.",700,700);
	c->Divide(1,1);
	
	c->cd(1);
	Double_t ymax = hPi0IM_MCSUM->GetMaximum();
	Double_t widthc1=getbinwidth(hPi0IM_OMEGAPI);
	hPi0IM_MCSUM->GetYaxis()->SetTitle(TString::Format("Entries/%0.1f MeV",widthc1));
	hPi0IM_MCSUM->GetXaxis()->SetTitle("M(#gamma#gamma) [MeV/c^{2}]");
	//hPi0IM_MCSUM->GetXaxis()->SetRangeUser(0.,70.);
	hPi0IM_MCSUM->GetYaxis()->SetRangeUser(0.,ymax*2);
	hPi0IM_MCSUM->GetYaxis()->SetTitleOffset(1.4);
	hPi0IM_MCSUM->Draw(); 
	hPi0IM_OMEGAPI->Draw("Same");
	hPi0IM_KPM->Draw("Same"); 	
	hPi0IM_KSL->Draw("Same");
	hPi0IM_THREEPIGAM->Draw("Same"); 
	hPi0IM_THREEPI->Draw("Same");
	hPi0IM_ETAGAM->Draw("Same"); 
	hPi0IM_BKGSUM1->Draw("Same");	
	hPi0IM_EEG->Draw("Same");
	hPi0IM_DATA->Draw("Samee1");
	TLine *l_cut1 = new TLine(pi0IMcut1,0.,pi0IMcut1,ymax*1.5); 
	TLine *l_cut2 = new TLine(pi0IMcut2,0.,pi0IMcut2,ymax*1.5); 
	format_l(l_cut1,4,2,1);
	format_l(l_cut2,4,2,1);
	l_cut1->Draw("Same");
	l_cut2->Draw("Same");
	
	legc1 = new TLegend(0.56,0.45,0.9,0.9);
	legc1->SetFillStyle(0); 
	legc1->SetBorderSize(0);  
	legc1->SetNColumns(2);
	
	legc1->AddEntry(hPi0IM_OMEGAPI,"#omega#pi^{0}","l");
	legc1->AddEntry(hPi0IM_KSL,"KSKL","l");
	legc1->AddEntry(hPi0IM_KPM,"KPM","l");
	legc1->AddEntry(hPi0IM_THREEPIGAM,"#pi^{+}#pi^{-}#pi^{0}#gamma","l");
	legc1->AddEntry(hPi0IM_THREEPI,"#pi^{+}#pi^{-}#pi^{0}","l");
	legc1->AddEntry(hPi0IM_THREEPIGAM,"#eta#gamma","l");
	legc1->AddEntry(hPi0IM_EEG,"e^{+}e^{-}#gamma","l");
	legc1->AddEntry(hPi0IM_BKGSUM1,"MC rest","l");
	legc1->AddEntry(hPi0IM_DATA,"Data","l");	
	legc1->AddEntry(hPi0IM_MCSUM,"ALLCHAIN","l");
	legc1->SetTextFont(132);
	legc1->Draw("Same");
	legtextsize(legc1, 0.03);
	
}	
