#include "Getname.C"
#include <iostream>
#include <string>
#include "gethisto.C"

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
	// compare histos
	double res[bin_Chi2], x[bin_Chi2], chi2sum=0.,chi2_temp=0., chi_temp = 0.;
	double data_temp = 0., mc_temp = 0.;
	int nbinX_d = hChi2_MCSUM->GetNbinsX();
	TAxis *xaxis_d = hChi2_MCSUM->GetXaxis();
	hChi2_MCSUM->Chi2Test(hChi2_DATA,"UW P",res);
	for (int i=1;i<=bin_Chi2;i++) {
		x[i]=xaxis_d->GetBinCenter(i);
		data_temp=hChi2_DATA->GetBinContent(i);
		mc_temp=hChi2_MCSUM->GetBinContent(i);
		chi_temp=(data_temp-mc_temp);
		chi2_temp=chi_temp*chi_temp/mc_temp;
		chi2sum+=chi2_temp;
		//cout<<mc_temp<<","<<data_temp<<","<<data_temp-mc_temp<<endl;
		//cout<<chi2_temp<<","<<chi2sum<<endl;
	}
	//cout<<chi2sum<<endl;
	//std::cout<<"chi2/ndf = "<<chi2<<endl;
	
	
	/// plots of unfitted histos
	TCanvas *c = new TCanvas("Chi2Distr","Chi2 Distr.",700,700);
	c->Divide(2);
	
	c->cd(1);
	Double_t ymax = hChi2_DATA->GetMaximum();
	Double_t widthc1=getbinwidth(hChi2_OMEGAPI);
	hChi2_DATA->GetYaxis()->SetTitle(TString::Format("Entries/%0.1f",widthc1));
	hChi2_DATA->GetXaxis()->SetTitle("#chi^{2}");
	//hChi2_DATA->GetXaxis()->SetRangeUser(2000.,xmax_Chi2);
	hChi2_DATA->GetYaxis()->SetRangeUser(1.,ymax*1.2);
	hChi2_DATA->GetYaxis()->SetTitleOffset(1.4);	 
	hChi2_DATA->Draw("e1");
	hChi2_OMEGAPI->Draw("Same");
	hChi2_KPM->Draw("Same"); 	
	hChi2_KSL->Draw("Same");
	hChi2_THREEPIGAM->Draw("Same"); 
	hChi2_THREEPI->Draw("Same");
	hChi2_ETAGAM->Draw("Same"); 
	hChi2_BKGSUM1->Draw("Same");	
	hChi2_EEG->Draw("Same");
	hChi2_MCSUM->Draw("Same");
	
	TLine *l_cut = new TLine(chi2cut,0.,chi2cut,ymax); 
	format_l(l_cut,4,2,1);
	l_cut->Draw("Same");
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
	
	legc1 = new TLegend(0.54,0.4,0.88,0.85);
	legc1->SetFillStyle(0); 
	legc1->SetBorderSize(0);  
	legc1->SetNColumns(2);
	
	legc1->AddEntry(hChi2_OMEGAPI,"#omega#pi^{0}","l");
	legc1->AddEntry(hChi2_KSL,"KSKL","l");
	legc1->AddEntry(hChi2_KPM,"KPM","l");
	legc1->AddEntry(hChi2_THREEPIGAM,"#pi^{+}#pi^{-}#pi^{0}#gamma","l");
	legc1->AddEntry(hChi2_THREEPI,"#pi^{+}#pi^{-}#pi^{0}","l");
	legc1->AddEntry(hChi2_THREEPIGAM,"#eta#gamma","l");
	legc1->AddEntry(hChi2_EEG,"e^{+}e^{-}#gamma","l");
	legc1->AddEntry(hChi2_BKGSUM1,"MC rest","l");
	legc1->AddEntry(hChi2_DATA,"Data","l");	
	legc1->AddEntry(hChi2_MCSUM,"ALLCHAIN","l");
	legc1->AddEntry(l_cut,"#chi^{2} cut","l");
	legc1->SetTextFont(132);
	legc1->Draw("Same");
	legtextsize(legc1, 0.03);
	
	c->cd(2);
	
	TFile hf("./Plots/Chi2Plots.root","recreate");
	c->Write();
	TGraph* gf= new TGraph(nbinX_d,x,res);
	gf->GetYaxis()->SetTitleOffset(1.2);
	gf->GetXaxis()->SetTitle("");
	gf->GetYaxis()->SetRangeUser(-10,10);
	gf->GetYaxis()->SetTitle("");	
	gf->SetLineWidth(3); 
	gf->SetMarkerStyle(21);
	gf->SetLineColor(1);
	gf->SetMarkerSize(.5);
	gf->SetTitle("Normalized Residuals");
	gf->Draw("AP");
  
  
	
}
