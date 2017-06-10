#include "Getname.C"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
#include "gethisto.C"

gSystem->Load("libRooFit");
using namespace std;
using namespace RooFit;

void DGFit(int *treeind, int *strind) {
	const int binnb=100;
	gStyle->SetOptStat(1);
	//cout<<treeind[0]<<endl;
	//cout<<strind[0]<<endl;
	TString str_temp = getbraname(strind[0]); // get branch name
	TString tree_temp = gettreename(treeind[0]);
	TFile *find_MC = new TFile("./ROOT/TREE_cutted.root","READ");
	//std::cout<<cutname[modpos]<<endl;
	//set fit inteval
	double xxmin = 0., xxmax = 0., mean_temp = 0., binwidth = 0.;
	if (strind[0] == 20) {
		xxmin=xmin_pi0IM, xxmax=xmax_pi0IM, mean_temp=xxmin+(xxmax-xxmin)/2;
	}
	else if (strind[0] == 19 || strind[0] == 10) {
		xxmin=-30., xxmax=30., mean_temp=0.;
		binwidth = (xxmax-xxmin)/binnb;
		cout<<"====================="<<binwidth<<endl;
	}
	//cout<<xxmin<<endl; cout<<xxmax<<endl;
	//declear variable
	
	RooRealVar x(str_temp,str_temp,xxmin,xxmax); 
	x.setBins(binnb);
	
	// construct gauss1	
   RooRealVar mean1("mean1","mean of gaussian1",mean_temp,xxmin,xxmax) ;
   RooRealVar sigma1("sigma1","width of gaussian1",2,0.1,10);
   // Build gaussian1 p.d.f in terms of x,mean and sigma
   RooGaussian gauss1("gauss1","gaussian1 PDF",x,mean1,sigma1);
   
   // construct gauss2	
   RooRealVar mean2("mean2","mean of gaussian2",xxmin+(xxmax-xxmin)/2,xxmin,xxmax) ;
   RooRealVar sigma2("sigma2","width of gaussian2",2,0.01,100);
   // Build gaussian1 p.d.f in terms of x,mean and sigma
   RooGaussian gauss2("gauss2","gaussian2 PDF",x,mean2,sigma2);
    
   // set model
   RooRealVar f1("f1","gauss1 fraction",0.5,0.,1.) ;
   
   // model(x) = f1*gauss1(x) + (1-f1)*gauss2(x);
   RooAddPdf model("model","model",RooArgList(gauss1,gauss2),f1); 
	// get MC or data sample
	TTree *tree = (TTree*)find_MC->Get("T"+tree_temp+"_Pre");
	
	RooDataSet mc("mc","mc",RooArgSet(x),Import(*tree)); 
	// Create a binned dataset with 20 bins and 500 events
   RooDataHist* hist1 = mc.binnedClone();
   // Represent data in dh as pdf in x
   RooHistPdf histpdf1("histpdf1","histpdf1",x,*hist1,0);
	
	/*RooPlot* xframe = x.frame(); 
	gauss.plotOn(xframe); 
	sigma = 3.; 
	gauss.plotOn(xframe,LineColor(kRed)); */
	
	

	// Make a second plot frame in x and draw both the 
   // data and the p.d.f in the frame
 
   RooPlot* frame1 = x.frame(Title("Gaussian p.d.f. with data"));
   histpdf1.plotOn(frame1,Name("MC"));
   //mc.plotOn(frame1);
   model.fitTo(mc,Range(-10,10)); 
   model.plotOn(frame1,Name("gauss1"),Components("gauss1"),LineStyle(kDashed),LineColor(kRed));
	model.plotOn(frame1,Name("gauss2"),Components("gauss2"),LineStyle(kDashed),LineColor(kBlack));
	model.plotOn(frame1,Name("gauss1+gauss2"),Components("gauss*"),LineStyle(kSolid),LineColor(kGreen)) ; 
	
	// A d d   b o x   w i t h   p d f   p a r a m e t e r s 
   // -----------------------------------------------------

   // Left edge of box starts at 55% of Xaxis)
   gauss2.paramOn(frame1,Layout(0.6,0.88,0.85));
   //mc.statOn(frame1,Layout(0.6,0.88,0.85)) ;
   frame1->getAttText()->SetTextSize(0.025);

	/*
   // A d d   b o x   w i t h   d a t a   s t a t i s t i c s
   // -------------------------------------------------------  

   // X size of box is from 55% to 99% of Xaxis range, top of box is at 80% of Yaxis range)
   data->statOn(frame,Layout(0.55,0.99,0.8)) ;*/
	
	// Print values of mean and sigma (that now reflect fitted values and errors)
   mean1.Print();
   sigma1.Print();
   
   mean2.Print();
   sigma2.Print();
   
   RooArgSet* params = gauss2.getVariables();
   RooRealVar* sigma2_fit = (RooRealVar*) params->find("sigma2") ; 

   // Draw all frames on a canvas
   TCanvas* c = new TCanvas("ggfit","model",800,800) ;
   c->Divide(1) ;
   c->cd(1) ; gPad->SetLeftMargin(0.15) ; frame1->GetYaxis()->SetTitleOffset(1.4); 
   
   if (strind[0] == 19) {
   	frame1->GetYaxis()->SetTitle(TString::Format("Entries/%0.1f [MeV]",binwidth));
   	frame1->GetXaxis()->SetTitle("M(#gamma#gamma)-M_{#pi^{0}} [MeV]");   	
   }
   else if (strind[0] == 10) {
   	frame1->GetYaxis()->SetTitle(TString::Format("Entries/%0.1f [MeV]",binwidth));
   	frame1->GetXaxis()->SetTitle("M(3#pi)_{rec}-M_{true} [MeV]");
   }	
   //
   TText* txt = new TText(2,100,"Signal") ;
  	txt->SetTextSize(0.04) ;
  	txt->SetTextColor(kRed) ;
  	frame1->addObject(txt) ;
   // Add arrow to frame
   double sigmascale = 3., sigcut = 0.; std::cout<<"<<<<<<<<<<<<<<"<<" sigma2_fit = "<<sigma2_fit->getVal()<<"<<<<<<<<<<<<<<"<<endl;
   double yy = 0.04, yy1 = 0.002,;
   sigcut  = sigmascale*sigma2_fit->getVal();
  	TArrow* arrow = new TArrow(-sigcut,yy,-sigcut,yy1,0.01,"|>") ;
  	TArrow* arrow1 = new TArrow(sigcut,yy,sigcut,yy1,0.01,"|>") ;
  	arrow->SetLineColor(kRed) ; arrow1->SetLineColor(kRed) ; 
  	arrow->SetFillColor(kRed) ; arrow1->SetFillColor(kRed) ;
  	arrow->SetLineWidth(3) ; arrow1->SetLineWidth(3) ;
  	frame1->addObject(arrow) ;
  	frame1->addObject(arrow1) ;
   frame1->Draw();
   legc1 = new TLegend(0.63,0.3,0.88,0.7);
	legc1->SetFillStyle(0); 
	legc1->SetBorderSize(0);  
	legc1->SetNColumns(1);
	
	legc1->AddEntry("MC","MC","l");
	legc1->AddEntry("gauss1","gauss1","l");
	legc1->AddEntry("gauss2","gauss2","l");
	legc1->AddEntry("gauss1+gauss2","gauss1+gauss2","l");
	legc1->SetTextFont(132);
	legc1->Draw("Same");
	legtextsize(legc1, 0.035);
   
   TFile hf("./Plots/"+str_temp+"_"+tree_temp+".root","recreate");
	c->Write();
}
