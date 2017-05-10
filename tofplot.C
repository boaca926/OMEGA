#include "Getname.C"
#include <iostream>
#include <string>
#include "gethisto.C"

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
	// determine standard cut
	// linear form y1=k1*x1+b1, determine parameter k and b
	// y2=k2*x2+b2=>if y1=y2=>k1*x+b1=k2*x+b2=>x=(b2-b1)/(k1-k2)
	// line1_std
	TLine *lh_std = new TLine(xmin_TOF,tofcut1,xmax_TOF,tofcut1); format_l(lh_std,4,2,3);
	Double_t kh_std = getkvalue(xmin_TOF,tofcut1,xmax_TOF,tofcut1); printf("kh_std = %g \n",kh_std);
	Double_t bh_std = getbvalue(kh_std,0.,xmin_TOF,tofcut1); printf("bh_std = %g \n",bh_std);
	// line2_std
	TLine *lv_std = new TLine(-1.8,xmax_TOF,2.2,xmin_TOF); format_l(lv_std,4,2,3);
	Double_t kv_std = getkvalue(-1.8,xmax_TOF,2.2,xmin_TOF); printf("kv_std = %g \n",kv_std);
	Double_t bv_std = getbvalue(kv_std,0.,-1.8,xmax_TOF); printf("bv_std = %g \n",bv_std);
	// get cross point standard
	Double_t lhlv_Xcross = getcrossx(kh_std,kv_std,bh_std,bv_std);
	Double_t lhlv_Ycross = getcrossy(kh_std,bh_std,lhlv_Xcross);
	printf("coss point: x=%g, y=%g\n",lhlv_Xcross,lhlv_Ycross);
	TLine *lh_std_cross = new TLine(xmin_TOF,tofcut1,lhlv_Xcross,lhlv_Ycross); format_l(lh_std_cross,4,2,3);
	TLine *lv_std_cross = new TLine(lhlv_Xcross,lhlv_Ycross,2.2,xmin_TOF); format_l(lv_std_cross,4,2,3);
	
	//
	TCanvas *c = new TCanvas("c","ToF scattered",700,700);
	c->Divide(2,2);
	
	c->cd(1);
	hToF_EEG->Draw("COLZ");
	gPad->SetLogz();
	hToF_EEG->GetXaxis()->SetTitle("#Deltat_{#pi^{#pm}}");
	hToF_EEG->GetYaxis()->SetTitle("#Deltat_{e^{#pm}}");
	
	c->cd(2);
	hToF_THREEPIGAM->Draw("COLZ");
	gPad->SetLogz(); 
	hToF_THREEPIGAM->GetXaxis()->SetTitle("#Deltat_{#pi^{#pm}}");
	hToF_THREEPIGAM->GetYaxis()->SetTitle("#Deltat_{e^{#pm}}");
	
	c->cd(3);
	hToF_MCSUM->Draw("COLZ");
	gPad->SetLogz();
	lh_std_cross->Draw();
	lv_std_cross->Draw("Same");
	Int_t index=0, nbstep_temp=1;
	double step_temp=cutstep_std[1]; 
	double lb_temp=Cutlist_std[1]-step_temp*nbstep_temp;
	Double_t upb_temp=Cutlist_std[1]+step_temp*nbstep_temp;
	while (lb_temp<upb_temp+step_temp) {
		// modify cut parameters, varie b term with a fix k value
		cout<<lb_temp<<endl;
		Double_t lhlv_Xcross_mod = getcrossx(kh_std,kv_std,lb_temp,bv_std);
		Double_t lhlv_Ycross_mod = getcrossy(kh_std,lb_temp,lhlv_Xcross_mod);
		TLine *lh_std_cross_mod = new TLine(xmin_TOF,getyvalue(kh_std,lb_temp,xmin_TOF),lhlv_Xcross_mod,lhlv_Ycross_mod);
		lh_std_cross_mod->Draw("Same");
		// draw
		if (lb_temp-Cutlist_std[1] > 0) {		 
			format_l(lh_std_cross_mod,2,1,1);
			TLine *lv_std_cross_mod = new TLine(lhlv_Xcross,lhlv_Ycross,lhlv_Xcross_mod,lhlv_Ycross_mod);
			format_l(lv_std_cross_mod,4,2,3);
			lv_std_cross_mod->Draw("Same");
		}
		else {
			format_l(lh_std_cross_mod,1,1,1);
		}
		
		lb_temp+=2*step_temp;
		index++;
	}
	
	hToF_MCSUM->GetXaxis()->SetTitle("#Deltat_{#pi^{#pm}}");
	hToF_MCSUM->GetYaxis()->SetTitle("#Deltat_{e^{#pm}}");
	
	c->cd(4);
	hToF_DATA->Draw("COLZ");
	gPad->SetLogz();
	lh_std_cross->Draw();
	lv_std_cross->Draw("Same"); 
	hToF_DATA->GetXaxis()->SetTitle("#Deltat_{#pi^{#pm}}");
	hToF_DATA->GetYaxis()->SetTitle("#Deltat_{e^{#pm}}");
	
	TCanvas *d = new TCanvas("d","ToF projection on Y",700,700);
	d->cd(1);
	Double_t ymax = H1D[10]->GetMaximum(); //cout<<ymax<<endl;
	H1D[8]->GetYaxis()->SetRangeUser(1.,ymax*1.1);
	H1D[8]->GetXaxis()->SetTitle("#Deltat_{e^{#pm}}");
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
	TLine *l_cut = new TLine(tofcut1,0.,tofcut1,ymax*0.8); 
	format_l(l_cut,4,1,3);
	l_cut->Draw("Same");
	//gPad->SetLogy();
	
	legd = new TLegend(0.52,0.5,0.93,0.90);
	legd->SetFillStyle(0); 
	legd->SetBorderSize(0);  
	legd->SetNColumns(2);
	legd->AddEntry(H1D[9],"Data","l");
	legd->AddEntry(H1D[8],"ALLCHAIN","l");
	legd->AddEntry(H1D[6],"MC rest","l");
	legd->AddEntry(H1D[5],"#eta#gamma","l");
	legd->AddEntry(H1D[4],"#pi^{+}#pi^{-}#pi^{0}","l");
	legd->AddEntry(H1D[3],"#pi^{+}#pi^{-}#pi^{0}#gamma","l");
	legd->AddEntry(H1D[2],"KSKL","l");
	legd->AddEntry(H1D[1],"KPM","l");
	legd->AddEntry(H1D[0],"#omega#pi^{0}","l"); 
	legd->AddEntry(l_cut,"#Deltat_{e^{#pm}} cut","l");
	legd->SetTextFont(132);
	legd->Draw("Same");
	legtextsize(legd, 0.02);
	
	TFile hf("./Plots/ToFPlots.root","recreate");
	c->Write();
}	
