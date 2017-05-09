#include "Getname.C"
#include <iostream>
#include <string>

void kinfitplot() {
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
	TH1D *hChi2_OMEGAPI = (TH1D*)f->Get("hChi2Value_"+OMEGAPI); 
	TH1D *hChi2_KPM = (TH1D*)f->Get("hChi2Value_"+KPM); 	
	TH1D *hChi2_KSL = (TH1D*)f->Get("hChi2Value_"+KSL); 
	TH1D *hChi2_THREEPIGAM = (TH1D*)f->Get("hChi2Value_"+THREEPIGAM); 
	TH1D *hChi2_THREEPI = (TH1D*)f->Get("hChi2Value_"+THREEPI);
	TH1D *hChi2_ETAGAM = (TH1D*)f->Get("hChi2Value_"+ETAGAM); 
	TH1D *hChi2_BKGSUM1 = (TH1D*)f->Get("hChi2Value_"+BKGSUM1); 
	TH1D *hChi2_BKGSUM2 = (TH1D*)f->Get("hChi2Value_"+BKGSUM2); 
	TH1D *hChi2_MCSUM = (TH1D*)f->Get("hChi2Value_"+MCSUM); 
	TH1D *hChi2_EEG = (TH1D*)f->Get("hChi2Value_"+EEG); 
	TH1D *hChi2_DATA = (TH1D*)f->Get("hChi2Value_"+DATA); 
	// add to TList
	TCollection* histlist = new TList;
	histlist->Add(hChi2_OMEGAPI);
	histlist->Add(hChi2_KPM);
	histlist->Add(hChi2_KSL);
	histlist->Add(hChi2_THREEPIGAM);
	histlist->Add(hChi2_THREEPI);
	histlist->Add(hChi2_ETAGAM);
	histlist->Add(hChi2_BKGSUM1);
	histlist->Add(hChi2_BKGSUM2);
	histlist->Add(hChi2_MCSUM);
	histlist->Add(hChi2_EEG);
	histlist->Add(hChi2_DATA);
	// normalize histos	
	TH1D *HCHI2_Norm[NbTree]; // list store normalized histos
	Int_t i=0;
	TObject* histout=0;
	TIter histliter(histlist);
	while((histout=histliter.Next()) !=0) {
		TH1D* histo_temp=dynamic_cast<TH1D*>(histout);
		TH1D *histo_normal=(TH1D*)histo_temp->Clone();
		normlizehisto(histo_normal, hChi2_MCSUM);
		HCHI2_Norm[i]=histo_normal;	
		i++;
	}
	
	/// plots of unfitted histos
	TCanvas *c = new TCanvas("Chi2Distr","Chi2 Distr.",700,700);
	c->Divide(1,1);
	
	c->cd(1);
	Double_t ymax = hChi2_MCSUM->GetMaximum();
	Double_t widthc1=getbinwidth(hChi2_OMEGAPI);
	hChi2_MCSUM->GetYaxis()->SetTitle(TString::Format("Entries/%0.1f",widthc1));
	hChi2_MCSUM->GetXaxis()->SetTitle("#chi^{2}");
	hChi2_MCSUM->GetXaxis()->SetRangeUser(0.,50.);
	hChi2_MCSUM->GetYaxis()->SetRangeUser(0.,ymax*1.2);
	hChi2_MCSUM->GetYaxis()->SetTitleOffset(1.4);
	hChi2_MCSUM->Draw(); 
	hChi2_OMEGAPI->Draw("Same");
	hChi2_KPM->Draw("Same"); 	
	hChi2_KSL->Draw("Same");
	hChi2_THREEPIGAM->Draw("Same"); 
	hChi2_THREEPI->Draw("Same");
	hChi2_ETAGAM->Draw("Same"); 
	hChi2_BKGSUM1->Draw("Same");	
	hChi2_EEG->Draw("Same");
	hChi2_DATA->Draw("Samee1");
	drawline(chi2cut,0.,chi2cut,ymax,1);
	/*HCHI2_Norm[8]->Draw();
	HCHI2_Norm[5]->Draw("Same");
	HCHI2_Norm[6]->Draw("Same");
	HCHI2_Norm[4]->Draw("Same");
	HCHI2_Norm[3]->Draw("Same");	
	HCHI2_Norm[2]->Draw("Same");
	HCHI2_Norm[1]->Draw("Same");
	HCHI2_Norm[0]->Draw("Same");
	HCHI2_Norm[9]->Draw("Same");
	HCHI2_Norm[10]->Draw("SameP");*/
	
	legc1 = new TLegend(0.55,0.4,0.85,0.85);
	legc1->SetFillStyle(0); 
	legc1->SetBorderSize(0);  
	legc1->SetNColumns(2);
	legc1->AddEntry(hChi2_THREEPIGAM,"#pi^{+}#pi^{-}#pi^{0}#gamma","l");
	legc1->AddEntry(hChi2_OMEGAPI,"#omega#pi^{0}","l");
	/*legc1->AddEntry(h3PiKSL,"KSKL","l");
	legc1->AddEntry(h3PiKMP,"KPM","l");
	legc1->AddEntry(h3PiThreepi,"#pi^{+}#pi^{-}#pi^{0}","l");
	legc1->AddEntry(h3PiIMEtagam,"#eta#gamma","l");
	legc1->AddEntry(h3PiEgg,"e^{+}e^{-}","l");
	legc1->AddEntry(h3PiIMPPg,"#pi^{+}#pi^{-}#gamma","l");
	legc1->AddEntry(h3PiIMBGRest,"MC rest","l");
	legc1->AddEntry(h3PiIMExp,"Data","l");	
	legc1->AddEntry(h3PiIMMcSum,"ALLCHAIN","l");*/
	legc1->SetTextFont(132);
	legc1->Draw("Same");
	legtextsize(legc1, 0.03);
	
	TFile hf("./Plots/Chi2Plots.root","recreate");
	c->Write();
	
}
