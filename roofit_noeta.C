#include "Getname.C"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"

gSystem->Load("libRooFit");
using namespace std;
using namespace RooFit;

void roofit_noeta() {
	// get root file
	TFile *findFile = new TFile("./ROOT/TREE_"+cutname[modpos]+".root","READ");
	// get tree name
	TString Data = gettreename(10);// data
	TString Sig = gettreename(3);// omega gamma
	TString Bkg1 = gettreename(0);// omega pi0
	TString Bkg2 = gettreename(2);// KSL
	TString Bkg3 = gettreename(7);// bkgsum2
	TString Bkg5 = gettreename(5);// etagam
	// declear variable
	RooRealVar x("ThreepiIM","ThreepiIM",xmin_IM,xmax_IM);
	//double scale=1.0/fsig;
	// get MC & DATA sample
	TTree *TData = (TTree*)findFile->Get("T"+Data+"_Pre"); // data
	double N_d=0;
   for (Int_t irow=0;irow<TData->GetEntries();irow++) {
   	N_d++;
   }
   std::cout<<"N_d = "<<N_d<<endl;
   // sig
	TTree *TThreePiGam = (TTree*)findFile->Get("T"+Sig+"_Pre"); // signal omega gamma
	double N_s=0;
	double f0_init=0;
   for (Int_t irow=0;irow<TThreePiGam->GetEntries();irow++) {
   	N_s++;
   }
   f0_init=N_s/N_d;
   std::cout<<"N_s = "<<N_s<<endl;
   td::cout<<"f0_init = "<<f0_init<<endl;
   //
	TTree *TOmegaPi = (TTree*)findFile->Get("T"+Bkg1+"_Pre"); // bkg1 omega pi0
	double N_bkg1=0;
	double f1_init=0;
   for (Int_t irow=0;irow<TOmegaPi->GetEntries();irow++) {
   	N_bkg1++;
   }
   f1_init=(N_bkg1/N_d)*5.7/8;
   std::cout<<"N_bkg1 = "<<N_bkg1<<endl;
   td::cout<<"f1_init = "<<f1_init<<endl;
   //
	TTree *TKSL = (TTree*)findFile->Get("T"+Bkg2+"_Pre"); // bkg2 ksl
	double N_bkg2=0;
	double f2_init=0;
   for (Int_t irow=0;irow<TKSL->GetEntries();irow++) {
   	N_bkg2++;
   }
   f2_init=N_bkg2/N_d;
   std::cout<<"N_bkg2 = "<<N_bkg2<<endl;
   td::cout<<"f2_init = "<<f2_init<<endl;
   //
	TTree *TBKGSUM2 = new TTree("T"+Bkg3+"_Pre","recreate"); // bkg3 bkgsum2
	double N_bkg3=0;
	double f3_init=0;
   for (Int_t irow=0;irow<TBKGSUM2->GetEntries();irow++) {
   	N_bkg3++;
   }
   f3_init=N_bkg3/N_d;
   std::cout<<"N_bkg3 = "<<N_bkg3<<endl;
   td::cout<<"f3_init = "<<f3_init<<endl;
	//
	TTree *TETAGAM = (TTree*)findFile->Get("T"+Bkg5+"_Pre"); // bkg5 etagam
	double N_bkg5=0;
	double f5_init=0;
   for (Int_t irow=0;irow<TETAGAM->GetEntries();irow++) {
   	N_bkg5++;
   }
   f5_init=N_bkg5/N_d;
   std::cout<<"N_bkg5 = "<<N_bkg5<<endl;
   td::cout<<"f5_init = "<<f5_init<<endl;
	// get pdfs
	// resolution
	RooRealVar mean("mean","mean of gaussian1",0.005,-1,1) ;
   RooRealVar sigma("sigma","width of gaussian1",1.874,0.1,10);
   // Build gaussian1 p.d.f in terms of x,mean and sigma
   //RooGaussian gauss("gauss","resolution PDF",x,mean,sigma);
	// data
	RooDataSet data("data","data",RooArgSet(x),Import(*TData));
	// sig pdf
	//RooDataSet sigsample("sigsample","sigsample",RooArgSet(x),Import(*TThreePiGam));
	RooDataSet sigsample("sigsample","sigsample",TThreePiGam,x);
	RooKeysPdf sigpdf("sigpdf", "sigpdf", x, sigsample, RooKeysPdf::MirrorBoth, 1);
	// bkg1 pdf
	RooDataSet bkg1sample("bkg1sample","bkg1sample",TOmegaPi,x);
	RooKeysPdf bkg1pdf("bkg1pdf", "bkg1pdf", x, bkg1sample, RooKeysPdf::MirrorBoth, 1);
	// bkg2 pdf
	RooDataSet bkg2sample("bkg2sample","bkg2sample",TKSL,x);
	RooKeysPdf bkg2pdf("bkg2pdf", "bkg2pdf", x, bkg2sample, RooKeysPdf::MirrorBoth, 1);
	// bkg3 pdf
	/*RooDataSet bkg3sample("bkg3sample","bkg3sample",TBKGSUM2,x);
	RooKeysPdf bkg3pdf("bkg3pdf", "bkg3pdf", x, bkg3sample, RooKeysPdf::MirrorBoth, 1);*/
	// bkg4 pdf
	/*RooRealVar c0("c0","coefficient #0", 0.1,-5.,5.); 
	RooRealVar c1("c1","coefficient #1", 0.1,-5.,5.); 
	RooRealVar c2("c2","coefficient #2", -0.1,-5.,5.); 
	RooChebychev bkg4pdf("bkg4pdf","bkg4pdf",x,RooArgList(c0,c1,c2));*/
	
	/*RooRealVar a0("a0","a0",0.5,0.,1.) ;
   RooRealVar a1("a1","a1",-0.2,0.,1.) ;
   RooChebychev bkg4pdf("bkg4pdf","bkg4pdf",x,RooArgSet(a0,a1)) ;*/
	
	RooRealVar argpar("argpar","argus shape parameter",-3,-100.,-1.); 
	//RooRealVar cut("argpar","argus shape parameter",900,850.,1000);
	RooArgusBG bkg4pdf("bkg4pdf","bkg4pdf",x,RooConst(910),argpar);
	//RooArgusBG bkg4pdf("bkg4pdf","bkg4pdf",x,900,argpar);
	// bkg5 pdf
	RooDataSet bkg5sample("bkg5sample","bkg5sample",TETAGAM,x);
	RooKeysPdf bkg5pdf("bkg5pdf", "bkg5pdf", x, bkg5sample, RooKeysPdf::MirrorBoth, 1);
	// get model
	RooRealVar sigfrac("sigfrac","sigfrac",f0_init,0.,1.);
	RooRealVar f1("f1","omega pi0",f1_init);
	RooRealVar f2("f2","ksl",f2_init);
	RooRealVar f5("f5","etagam",f5_init);
	RooRealVar f4("f4","argus",1-f0_init-f1_init-f2_init-f5_init,0.,1.);
	RooAddPdf bkgsum("bkgsum","Bkgsum",RooArgList(bkg1pdf,bkg2pdf,bkg4pdf,bkg5pdf),RooArgList(f1,f2,f4,f5)) ;
	RooAddPdf sig("sig","Signal",sigpdf,sigfrac) ;
	RooAddPdf model("model","model",RooArgList(sigpdf,bkgsum),sigfrac);
	RooRealVar nsig("nsig","signal fraction",10000,0.,100000.) ;
	RooRealVar nbkg("nbkg","background fraction",5000,0.,100000.) ;
	//RooAddPdf model("model","model",RooArgList(sig,bkgsum),RooArgList(nsig,nbkg));
	// Draw all frames on a canvas
	RooPlot* frame = x.frame(); 
	//data.plotOn(frame);
	data.plotOn(frame); 
	model.plotOn(frame,LineStyle(kSolid),LineColor(kRed));
	//gauss.plotOn(frame,LineStyle(kSolid),LineColor(6));
	//sigpdf.plotOn(frame,LineStyle(kSolid),LineColor(4)); 
	//bkg1pdf.plotOn(frame,LineStyle(kSolid),LineColor(7));
	//bkg2pdf.plotOn(frame,LineStyle(kSolid),LineColor(15)); 
	//bkg3pdf.plotOn(frame,LineStyle(kSolid),LineColor(2));
	//bkg4pdf.plotOn(frame,LineStyle(kSolid),LineColor(1));
	//bkg5pdf.plotOn(frame,LineStyle(kSolid),LineColor(5));
	// fit
	double scale_temp = 16;
	double range1 = omegmass-scale_temp*masswidth, range2 = omegmass+scale_temp*masswidth;
	RooFitResult* rf = model.fitTo(data,Range(range1,range2));
	//model.fitTo(data,Range(range1,range2),Extended(kTRUE));
	model.plotOn(frame,Name("bkg2pdf"),Components("bkg2pdf"),LineStyle(kDashed),LineColor(15),LineWidth(2));
	model.plotOn(frame,Name("bkg4pdf"),Components("bkg4pdf"),LineStyle(kDashed),LineColor(1),LineWidth(2));
	model.plotOn(frame,Name("sigpdf"),Components("sigpdf"),LineStyle(kDashed),LineColor(4),LineWidth(2));
	model.plotOn(frame,Name("bkg1pdf"),Components("bkg1pdf"),LineStyle(kDashed),LineColor(7),LineWidth(2));
	model.plotOn(frame,Name("bkg5pdf"),Components("bkg5pdf"),LineStyle(kDashed),LineColor(3),LineWidth(2));
	//add parameter estimated signals: esig
	double esig = N_d*sigfrac.getVal();
	//double eint = 
	model.Print("t");
   TCanvas* c = new TCanvas("IMfit","IMfit",800,400) ;
   //
   x.setRange("window",range1,range2) ;
   RooAbsReal* fracSigRange = sigpdf.createIntegral(x,x,"window");
   RooAbsReal* fracBkg1Range = bkg1pdf.createIntegral(x,x,"window");
   RooAbsReal* fracBkg4Range = bkg4pdf.createIntegral(x,x,"window");
   std::cout<<"<<<<<<<<<<<<<<"<<" fit x range: ["<<range1<<","<<range2<<"]"<<" <<<<<<<<<<<<<<"<<endl;
   std::cout<<"<<<<<<<<<<<<<<"<<" total number of signal = "<<esig<<" <<<<<<<<<<<<<<"<<endl;
   RooArgSet* params = model.getVariables();
   params->Print("v");
   //Double_t nsigWindow = nsig.getVal() * fracSigRange->getVal() ;
   std::cout<<"<<<<<<<<<<<<<<"<<" sig_frac = "<<fracSigRange->getVal()<<"<<<<<<<<<<<<<<"<<endl;
   //std::cout<<"<<<<<<<<<<<<<<"<<" bkg1_sum = "<<fracBkg1Range->getVal()<<"<<<<<<<<<<<<<<"<<endl;
   //std::cout<<"<<<<<<<<<<<<<<"<<" bkg4_sum = "<<fracBkg4Range->getVal()<<"<<<<<<<<<<<<<<"<<endl;
   //std::cout<<"<<<<<<<<<<<<<<"<<" f1 = "<<f1.getVal()<<"<<<<<<<<<<<<<<"<<endl;
   //
   //
   c->Divide(1) ;
   c->cd(1); 
   gPad->SetLeftMargin(0.15); 
   frame->GetXaxis()->SetRangeUser(range1,range2);
   frame->GetYaxis()->SetTitleOffset(1.6); 
   frame->Draw();
   
   TFile hf("./Plots/fitresult.root","recreate");
	c->Write();
}
