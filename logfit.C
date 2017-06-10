TH1D *hThreepiIM_THREEPIGAM, *hThreepiIM_OMEGAPI, *hThreepiIM_DATA, *hThreepiIM_ETAGAM, *hThreepiIM_KSL, *hsum;

double N_mc = 0, N_d = 0, N_s = 0, N_b1 = 0, N_b2 = 0, N_b3 = 0, N_b4 = 0;
Int_t npfits=0;

#include "gethisto.C"
#include "Getname.C"

Double_t myfunc(Double_t *x, Double_t *par) {
   Double_t xx = x[0];
   Int_t bin = hThreepiIM_DATA->GetXaxis()->FindBin(xx);
   N_b4=N_d-(N_s+N_b1+N_b2+N_b3);
   Double_t ws = N_d*par[0]/N_s; //std::cout<<"ws = "<<ws<<endl;
   Double_t wb1 = N_d*par[1]/N_b1;
   Double_t wb2 = N_d*par[2]/N_b2;
   Double_t wb3 = N_d*par[3]/N_b3;
   Double_t wb4 = N_d*(1-par[0]-par[1]-par[2]-par[3])/N_b4;
   
   
   Double_t s = hThreepiIM_THREEPIGAM->GetBinContent(bin);
   Double_t b1 = hThreepiIM_OMEGAPI->GetBinContent(bin);
   Double_t b2 = hThreepiIM_ETAGAM->GetBinContent(bin);
   Double_t b3 = hThreepiIM_KSL->GetBinContent(bin);
   Double_t b4 = hsum->GetBinContent(bin);
   Double_t br = ws*s+wb1*b1+wb2*b2+wb3*b3+wb4*b4;
   
   //cout<<N_s<<endl;
   return br;
}

void myFcn(Int_t & /*nPar*/, Double_t * /*grad*/ , Double_t &fval, Double_t *p, Int_t /*iflag */  ){
//void myFcn(Double_t *p){ 
	TAxis *xaxis_d = hThreepiIM_DATA->GetXaxis(); 
   Int_t nbinX_d = hThreepiIM_DATA->GetNbinsX();
  
	double n2lL =0.;
	double x[1];
	double tmp=0.;
	
	for (Int_t i = 1; i <= nbinX_d; ++i) {
		x[0]=xaxis_d->GetBinCenter(i);	
   	tmp = hThreepiIM_DATA->GetBinContent(i)-myfunc(x,p); 
   	//cout<<tmp<<endl;
   	n2lL+= tmp*tmp; //cout<<error_d<<endl;
      npfits++;
   }
   //cout<<hThreepiIM_DATA->GetXaxis()->GetBinCenter(1)<<endl;
	fval = n2lL;
  //printf("p0 = %g, p1 = %g \n",p[0],p[1]);

}

void logfit() {
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
	hThreepiIM_OMEGAPI = (TH1D*)f->Get("hIM_"+OMEGAPI); 
	TH1D *hThreepiIM_OMEGAPI_nofit=(TH1D*)hThreepiIM_OMEGAPI->Clone();
	TH1D *hThreepiIM_OMEGAPI_fit=(TH1D*)hThreepiIM_OMEGAPI->Clone();
	
	//
	TH1D *hThreepiIM_KPM= (TH1D*)f->Get("hIM_"+KPM); 
	//	
	hThreepiIM_KSL = (TH1D*)f->Get("hIM_"+KSL); 
	TH1D *hThreepiIM_KSL_fit=(TH1D*)hThreepiIM_KSL->Clone();
	TH1D *hThreepiIM_KSL_nofit=(TH1D*)hThreepiIM_KSL->Clone();
	//
	hThreepiIM_THREEPI = (TH1D*)f->Get("hIM_"+THREEPI); 
	//
	hThreepiIM_THREEPIGAM = (TH1D*)f->Get("hIM_"+THREEPIGAM); 
	TH1D *hThreepiIM_THREEPIGAM_fit = (TH1D*)hThreepiIM_THREEPIGAM->Clone();
	TH1D *hThreepiIM_THREEPIGAM_nofit = (TH1D*)hThreepiIM_THREEPIGAM->Clone();
	//
	hThreepiIM_ETAGAM = (TH1D*)f->Get("hIM_"+ETAGAM); 
	TH1D *hThreepiIM_ETAGAM_fit=(TH1D*)hThreepiIM_ETAGAM->Clone();
	TH1D *hThreepiIM_ETAGAM_nofit=(TH1D*)hThreepiIM_ETAGAM->Clone();
	//
	TH1D *hThreepiIM_BKGSUM1 = (TH1D*)f->Get("hIM_"+BKGSUM1); 
	TH1D *hThreepiIM_BKGSUM2 = (TH1D*)f->Get("hIM_"+BKGSUM2); 
	TH1D *hThreepiIM_MCSUM = (TH1D*)f->Get("hIM_"+MCSUM); 
	TH1D *hThreepiIM_EEG = (TH1D*)f->Get("hIM_"+EEG); 
	//
	hThreepiIM_DATA = (TH1D*)f->Get("hIM_"+DATA); 
	TH1D *hThreepiIM_DATA_fit = (TH1D*)hThreepiIM_DATA->Clone();
	TH1D *hThreepiIM_DATA_nofit = (TH1D*)hThreepiIM_DATA->Clone();
	// bkgsum
   hsum = (TH1D*)hThreepiIM_BKGSUM1->Clone(); // add bkgsum1
   hsum->Add(hThreepiIM_KPM,1); // add kpm
   hsum->Add(hThreepiIM_THREEPI,1); // add threepi
   hsum->Add(hThreepiIM_EEG,1); // add eeg 
   TH1D *hsum_fit=(TH1D*)hsum->Clone();
   N_b4=getentriesfit(hsum);
   std::cout<<"N_b4 = "<<N_b4<<endl;
   // total MC
   TH1D *hmcsum = (TH1D*)hsum->Clone();
   hmcsum->Add(hThreepiIM_THREEPIGAM,1); // add omegam
   hmcsum->Add(hThreepiIM_OMEGAPI,1); // add omega pi0
   hmcsum->Add(hThreepiIM_ETAGAM,1); // add eta gamma
   hmcsum->Add(hThreepiIM_KSL,1); // add eta ksl
   TH1D *hmcsum_nofit=(TH1D*)hmcsum->Clone();
   format_h(hmcsum_nofit,2,0,1);
   //
	TCanvas *e = new TCanvas("unfitted","unfitted",700,700);
	e->Divide(1,1);	
	hThreepiIM_DATA_nofit->Draw("E1");
	hThreepiIM_KSL_nofit->Draw("Same"); 
	hThreepiIM_OMEGAPI_nofit->Draw("Same"); 
	hThreepiIM_ETAGAM_nofit->Draw("Same"); 
	hThreepiIM_THREEPIGAM_nofit->Draw("Same");
	hmcsum_nofit->Draw("Same");
	//
   N_mc=getentriesfit(hmcsum);
   std::cout<<"N_mc = "<<N_mc<<endl;
   //
	N_d=getentriesfit(hThreepiIM_DATA); 
	std::cout<<"N_d = "<<N_d<<endl;
	// sig omega gamma
	N_s=getentriesfit(hThreepiIM_THREEPIGAM);
	double f0_init = N_s/N_mc;
	std::cout<<"N_s = "<<N_s<<" f0_init = "<<f0_init<<endl;
	// bkg1 omega pi0
   N_b1=getentriesfit(hThreepiIM_OMEGAPI);
   double f1_init = N_b1/N_mc;
   std::cout<<"N_b1 = "<<N_b1<<" f1_init = "<<f1_init<<endl;
   // bkg2 eta gamma
   N_b2=getentriesfit(hThreepiIM_ETAGAM);
   double f2_init = N_b2/N_mc;
   std::cout<<"N_b2 = "<<N_b2<<" f2_init = "<<f2_init<<endl;
   // bkg3 ksl
   N_b3=getentriesfit(hThreepiIM_KSL);
   double f3_init = N_b3/N_mc;
   std::cout<<"N_b3 = "<<N_b3<<" f3_init = "<<f3_init<<endl;
	///
   Double_t Parameter_new[4]={f0_init,f1_init,f2_init,f3_init};
   TF1 * func = new TF1("func",myfunc,xmin_IM,xmax_IM,4);
   func->SetParameters(Parameter_new);
   // get result
	TFitResultPtr rr = hThreepiIM_DATA->Fit("func","SL","",xmin_IM,xmax_IM);
	double chi2 = rr->Chi2();  
   double ndf =  rr->Ndf();
   std::cout << "chi2 = " <<chi2<<endl;
   std::cout << "Ndf = " <<ndf<<endl;
   std::cout << "chi2_ndf = " <<chi2/ndf<<endl;
   Double_t P[4];
   P[0] = func->GetParameter(0); cout<<P[0]<<endl;
   P[1] = func->GetParameter(1); cout<<P[1]<<endl;
   P[2] = func->GetParameter(2); cout<<P[2]<<endl;
   P[3] = func->GetParameter(3); cout<<P[3]<<endl;
   //
   Double_t S_s = N_d*P[0]/N_s; std::cout<<"S_s = "<<S_s<<endl;
   Double_t S_b1 = N_d*P[1]/N_b1; std::cout<<"S_b1 = "<<S_b1<<endl;
   Double_t S_b2 = N_d*P[2]/N_b2; std::cout<<"S_b2 = "<<S_b1<<endl;
   Double_t S_b3 = N_d*P[3]/N_b3; std::cout<<"S_b3 = "<<S_b3<<endl;
   Double_t S_b4 = N_d*(1-P[0]-P[1]-P[2]-P[3])/N_b4; std::cout<<"S_b4 = "<<S_b4<<endl;
	//
   /*std::cout << "Do global fit" << std::endl;
   TVirtualFitter::SetDefaultFitter("Minuit");
   TVirtualFitter * minuit = TVirtualFitter::Fitter(0,4);
   for (Int_t i = 0; i < 4; ++i) {  
    minuit->SetParameter(i, func->GetParName(i), func->GetParameter(i),0.001,0,0);
    //cout<<func->GetParName(i)<<endl;
    //cout<<func->GetParameter(i)<<endl;
  }
   minuit->SetFCN(myFcn);
   Double_t arglist[100];
   arglist[0] = 0;
   // minimize
   arglist[0] = 10000; // number of function calls
   arglist[1] = 0.01; // tolerance
   minuit->ExecuteCommand("MIGRAD",arglist,2);*/
   
   /// plots of unfitted histos
	TCanvas *d = new TCanvas("fitted","fitted",700,700);
	d->Divide(1,1);
	
	Double_t ymax = hThreepiIM_DATA_fit->GetMaximum();
	Double_t widthc1=getbinwidth(hThreepiIM_DATA_fit);
	hThreepiIM_DATA_fit->GetYaxis()->SetTitle(TString::Format("Entries/%0.1f [MeV]",widthc1));
	hThreepiIM_DATA_fit->GetXaxis()->SetTitle("M(3#pi) [MeV]");
	//hThreepiIM_DATA_fit->GetYaxis()->SetRangeUser(0.,ymax*1.2);
	hThreepiIM_KSL_fit->Scale(S_b3);
	hsum_fit->Scale(S_b4);
	hThreepiIM_THREEPIGAM_fit->Scale(S_s);
	hThreepiIM_OMEGAPI_fit->Scale(S_b1);
	hThreepiIM_ETAGAM_fit->Scale(S_b2);
	TH1D *hmcsum_fit=(TH1D*)hThreepiIM_KSL_fit->Clone();
	hmcsum_fit->Add(hThreepiIM_OMEGAPI_fit,1);
	hmcsum_fit->Add(hThreepiIM_ETAGAM_fit,1);
	hmcsum_fit->Add(hThreepiIM_THREEPIGAM_fit,1);
	hmcsum_fit->Add(hsum_fit,1);
	format_h(hmcsum_fit,2,0,2);
	//
	hThreepiIM_DATA_fit->GetYaxis()->SetTitleOffset(1.2);
	hThreepiIM_DATA_fit->Draw("E1");
	hmcsum_fit->Draw("Same");
	hThreepiIM_KSL_fit->Draw("Same");
	hThreepiIM_OMEGAPI_fit->Draw("Same");
	hThreepiIM_ETAGAM_fit->Draw("Same");
	hThreepiIM_THREEPIGAM_fit->Draw("Same");
	hsum_fit->Draw("Same");
	//
	legc1 = new TLegend(0.64,0.4,0.88,0.85);
	legc1->SetFillStyle(0); 
	legc1->SetBorderSize(0);  
	legc1->SetNColumns(1);
	
	legc1->AddEntry(hThreepiIM_OMEGAPI_fit,"#omega#pi^{0}","l");
	legc1->AddEntry(hThreepiIM_KSL_fit,"KSKL","l");
	legc1->AddEntry(hThreepiIM_THREEPIGAM_fit,"#pi^{+}#pi^{-}#pi^{0}#gamma","l");
	legc1->AddEntry(hThreepiIM_ETAGAM_fit,"#eta#gamma","l");
	legc1->AddEntry(hThreepiIM_DATA_fit,"Data","l");	

	legc1->SetTextFont(132);
	legc1->Draw("Same");
	legtextsize(legc1, 0.03); 
	
	TFile hf("./Plots/threepiIMfitted.root","recreate");
	d->Write();
	e->Write();
	
}
