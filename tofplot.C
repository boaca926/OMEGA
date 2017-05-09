#include "Getname.C"
#include <iostream>
#include <string>

void tofplot() {
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
	TH2D *hToF_OMEGAPI = (TH2D*)f->Get("hToF_"+OMEGAPI); 
	TH2D *hToF_KPM = (TH2D*)f->Get("hToF_"+KPM); 	
	TH2D *hToF_KSL = (TH2D*)f->Get("hToF_"+KSL); 
	TH2D *hToF_THREEPIGAM = (TH2D*)f->Get("hToF_"+THREEPIGAM); 
	TH2D *hToF_THREEPI = (TH2D*)f->Get("hToF_"+THREEPI);
	TH2D *hToF_ETAGAM = (TH2D*)f->Get("hToF_"+ETAGAM); 
	TH2D *hToF_BKGSUM1 = (TH2D*)f->Get("hToF_"+BKGSUM1); 
	TH2D *hToF_BKGSUM2 = (TH2D*)f->Get("hToF_"+BKGSUM2); 
	TH2D *hToF_MCSUM = (TH2D*)f->Get("hToF_"+MCSUM); 
	TH2D *hToF_EEG = (TH2D*)f->Get("hToF_"+EEG); 
	TH2D *hToF_DATA = (TH2D*)f->Get("hToF_"+DATA);
	
	// add to TList
	TCollection* histlist = new TList;
	histlist->Add(hToF_OMEGAPI);
	histlist->Add(hToF_KPM);
	histlist->Add(hToF_KSL);
	histlist->Add(hToF_THREEPIGAM);
	histlist->Add(hToF_THREEPI);
	histlist->Add(hToF_ETAGAM);
	histlist->Add(hToF_BKGSUM1);
	histlist->Add(hToF_BKGSUM2);
	histlist->Add(hToF_MCSUM);
	histlist->Add(hToF_EEG);
	histlist->Add(hToF_DATA);
	// make projection	
	TH1D *H1D[NbTree]; // list store normalized histos
	Int_t i=0;
	TObject* histout=0;
	TIter histliter(histlist);
	while((histout=histliter.Next()) !=0) {
		TH2D* histo_temp=dynamic_cast<TH2D*>(histout);
		H1D[i]=histo_temp->ProjectionY();	
		format_h(H1D[i],colorid[i],0,1);
		i++;
	}
	
	TCanvas *c = new TCanvas("c","ToF scattered",700,700);
	c->Divide(2,2);
	
	c->cd(1);
	hToF_EEG->Draw("COLZ");
	gPad->SetLogz();
	//drawline(100.,620.,450.,250.,1); 
	//drawline(100.,590.,450.,220.,1);  
	//drawline(0.65,700.,1.,450.,1); 
	//drawline(0.85,700.,1.,200.,1);
	
	c->cd(2);
	hToF_THREEPIGAM->Draw("COLZ");
	gPad->SetLogz();
	
	c->cd(3);
	hToF_MCSUM->Draw("COLZ");
	gPad->SetLogz();
	
	c->cd(4);
	hToF_DATA->Draw("COLZ");
	gPad->SetLogz();
	
	TCanvas *d = new TCanvas("d","ToF projection on Y",700,700);
	d->cd(1);
	H1D[10]->SetMarkerStyle(2);
	H1D[8]->Draw();
	H1D[5]->Draw("Same");
	H1D[6]->Draw("Same");
	H1D[4]->Draw("Same");
	H1D[3]->Draw("Same");	
	H1D[2]->Draw("Same");
	H1D[1]->Draw("Same");
	H1D[0]->Draw("Same");
	H1D[9]->Draw("Same");
	H1D[10]->Draw("SameP");
	gPad->SetLogy();
	
	TFile hf("./Plots/ToFPlots.root","recreate");
	c->Write();
}	
