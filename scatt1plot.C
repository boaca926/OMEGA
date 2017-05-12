#include "Getname.C"
#include <iostream>
#include <string>
#include "gethisto.C"

void scatt1plot() {
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
	TH2D *HScatter1_OMEGAPI = (TH2D*)f->Get("HScatter1_"+OMEGAPI); 
	TH2D *HScatter1_KPM = (TH2D*)f->Get("HScatter1_"+KPM); 	
	TH2D *HScatter1_KSL = (TH2D*)f->Get("HScatter1_"+KSL); 
	TH2D *HScatter1_THREEPIGAM = (TH2D*)f->Get("HScatter1_"+THREEPIGAM); 
	TH2D *HScatter1_THREEPI = (TH2D*)f->Get("HScatter1_"+THREEPI);
	TH2D *HScatter1_ETAGAM = (TH2D*)f->Get("HScatter1_"+ETAGAM); 
	TH2D *HScatter1_BKGSUM1 = (TH2D*)f->Get("HScatter1_"+BKGSUM1); 
	TH2D *HScatter1_BKGSUM2 = (TH2D*)f->Get("HScatter1_"+BKGSUM2); 
	TH2D *HScatter1_MCSUM = (TH2D*)f->Get("HScatter1_"+MCSUM); 
	TH2D *HScatter1_EEG = (TH2D*)f->Get("HScatter1_"+EEG); 
	TH2D *HScatter1_DATA = (TH2D*)f->Get("HScatter1_"+DATA);
	
	// add to TList
	TCollection* histlist = new TList;
	histlist->Add(HScatter1_OMEGAPI);
	histlist->Add(HScatter1_KPM);
	histlist->Add(HScatter1_KSL);
	histlist->Add(HScatter1_THREEPIGAM);
	histlist->Add(HScatter1_THREEPI);
	histlist->Add(HScatter1_ETAGAM);
	histlist->Add(HScatter1_BKGSUM1);
	histlist->Add(HScatter1_BKGSUM2);
	histlist->Add(HScatter1_MCSUM);
	histlist->Add(HScatter1_EEG);
	histlist->Add(HScatter1_DATA);
	// make projection	
	TH1D *H1D_tracksum[NbTree]; // list store normalized histos
	TH1D *H1D_deltaE[NbTree];
	Int_t i=0;
	TObject* histout=0;
	TIter histliter(histlist);
	while((histout=histliter.Next()) !=0) {
		TH2D* histo_temp=dynamic_cast<TH2D*>(histout);
		H1D_tracksum[i]=histo_temp->ProjectionX();	
		H1D_deltaE[i]=histo_temp->ProjectionY();
		format_h(H1D_tracksum[i],colorid[i],0,1);
		format_h(H1D_deltaE[i],colorid[i],0,1);
		i++;
	}
	
	TCanvas *c = new TCanvas("c","track momenta sum vs delta E",700,700);
	c->Divide(3,1);
	TLine *l_cut = new TLine(xmin_Tracksum,deltaEcut,xmax_Tracksum,deltaEcut); format_l(l_cut,4,1,1);
	TLine *l1_cut = new TLine(xmin_Tracksum,deltaEcut+cutstep_std[3],xmax_Tracksum,deltaEcut+cutstep_std[3]); format_l(l1_cut,2,1,1);
	TLine *l2_cut = new TLine(xmin_Tracksum,deltaEcut-cutstep_std[3],xmax_Tracksum,deltaEcut-cutstep_std[3]); format_l(l2_cut,1,1,1);
	c->cd(1);
	HScatter1_THREEPIGAM->GetXaxis()->SetTitle("#left|#bar{p}_{#pi^{+}}#right|+#left|#bar{p}_{#pi^{-}}#right|");
	HScatter1_THREEPIGAM->GetYaxis()->SetTitle("#deltaE");
	HScatter1_THREEPIGAM->GetYaxis()->SetTitleOffset(1.4);
	HScatter1_THREEPIGAM->Draw("COLZ");
	l_cut->Draw("Same");
	l1_cut->Draw("Same");
	l2_cut->Draw("Same");
	gPad->SetLogz();
	
	c->cd(2);
	HScatter1_MCSUM->GetXaxis()->SetTitle("#left|#bar{p}_{#pi^{+}}#right|+#left|#bar{p}_{#pi^{-}}#right|");
	HScatter1_MCSUM->GetYaxis()->SetTitle("#deltaE");
	HScatter1_MCSUM->GetYaxis()->SetTitleOffset(1.4);
	HScatter1_MCSUM->Draw("COLZ");
	l_cut->Draw("Same");
	l1_cut->Draw("Same");
	l2_cut->Draw("Same");
	gPad->SetLogz();
	
	c->cd(3);
	HScatter1_DATA->GetXaxis()->SetTitle("#left|#bar{p}_{#pi^{+}}#right|+#left|#bar{p}_{#pi^{-}}#right|");
	HScatter1_DATA->GetYaxis()->SetTitle("#deltaE");
	HScatter1_DATA->GetYaxis()->SetTitleOffset(1.4);
	HScatter1_DATA->Draw("COLZ");
	l_cut->Draw("Same");
	l1_cut->Draw("Same");
	l2_cut->Draw("Same");
	gPad->SetLogz();
	
	TCanvas *d = new TCanvas("d","track momenta sum vs delta E 1D projection",700,700);
	d->Divide(2,1);
	d->cd(1);
	Double_t ymax = H1D_deltaE[8]->GetMaximum(); //cout<<ymax<<endl;
	Double_t widthc1=getbinwidth(H1D_deltaE[8]);
	H1D_deltaE[8]->GetYaxis()->SetTitle(TString::Format("Entries/%0.1f",widthc1));
	H1D_deltaE[8]->GetYaxis()->SetRangeUser(1.,ymax*1.1);
	H1D_deltaE[8]->GetXaxis()->SetTitle("#deltaE");
	H1D_deltaE[8]->GetYaxis()->SetTitleOffset(1.4);
	H1D_deltaE[10]->SetMarkerStyle(2);
	H1D_deltaE[8]->Draw();
	H1D_deltaE[5]->Draw("Same");
	H1D_deltaE[6]->Draw("Same");
	H1D_deltaE[4]->Draw("Same");
	H1D_deltaE[3]->Draw("Same");	
	H1D_deltaE[2]->Draw("Same");
	H1D_deltaE[1]->Draw("Same");
	H1D_deltaE[0]->Draw("Same");
	H1D_deltaE[9]->Draw("Same");
	H1D_deltaE[10]->Draw("SameP");
	
	d->cd(2);
	Double_t ymax = H1D_tracksum[8]->GetMaximum(); //cout<<ymax<<endl;
	Double_t widthc1=getbinwidth(H1D_tracksum[8]);
	H1D_tracksum[8]->GetYaxis()->SetTitle(TString::Format("Entries/%0.1f",widthc1));
	H1D_tracksum[8]->GetYaxis()->SetRangeUser(1.,ymax*1.1);
	H1D_tracksum[8]->GetXaxis()->SetTitle("#left|#bar{p}_{#pi^{+}}#right|+#left|#bar{p}_{#pi^{-}}#right|");
	H1D_tracksum[8]->GetYaxis()->SetTitleOffset(1.4);
	H1D_tracksum[10]->SetMarkerStyle(2);
	H1D_tracksum[8]->Draw();
	H1D_tracksum[5]->Draw("Same");
	H1D_tracksum[6]->Draw("Same");
	H1D_tracksum[4]->Draw("Same");
	H1D_tracksum[3]->Draw("Same");	
	H1D_tracksum[2]->Draw("Same");
	H1D_tracksum[1]->Draw("Same");
	H1D_tracksum[0]->Draw("Same");
	H1D_tracksum[9]->Draw("Same");
	H1D_tracksum[10]->Draw("SameP");
	
	
	
}	
