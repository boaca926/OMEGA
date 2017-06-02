#include "Getname.C"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
#include "gethisto.C"

gSystem->Load("libRooFit");
using namespace std;
using namespace RooFit;

void modelfit() {
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
	// declear variable
	RooRealVar x("x","x",xmin_IM,xmax_IM); 
	RooPlot* frame = x.frame(Title("model"));
	// construct model
	double mcsumbn = 0., signb = 0., bkg1nb = 0., bkg2nb = 0., bkg3nb = 0., bkg4nb = 0.;
   double f0_init=0., f1_init=0., f2_init=0., f3_init=0., f4_init=0.;
   RooDataHist data("data","data",x,Import(*hThreepiIM_DATA));
   data.plotOn(frame);
	// bkgsum
   TH1D *hsum = (TH1D*)hThreepiIM_BKGSUM1->Clone(); // add bkgsum1
   hsum->Add(hThreepiIM_KPM,1); // add kpm
   hsum->Add(hThreepiIM_THREEPI,1); // add threepi
   hsum->Add(hThreepiIM_EEG,1); // add eeg
   RooDataHist bkgsum("bkgsum","bkgsum",x,Import(*hsum)); 
	RooHistPdf bkgsumpdf("bkgsumpdf","bkgsumpdf",x,bkgsum,0) ;	
   //bkgsumpdf.plotOn(frame,Name("bkgsum_MC"),LineStyle(kSolid),LineColor(20));
   // total MC
   TH1D *hmcsum = (TH1D*)hsum->Clone();
   hmcsum->Add(hThreepiIM_THREEPIGAM,1); // add omegam
   hmcsum->Add(hThreepiIM_OMEGAPI,1); // add omega pi0
   hmcsum->Add(hThreepiIM_ETAGAM,1); // add eta gamma
   hmcsum->Add(hThreepiIM_KSL,1); // add eta ksl
   mcsumnb=getentriesfit(hmcsum); 
	std::cout<<"mc sum nb = "<<mcsumnb<<endl;
	//
	bkg4nb=getentriesfit(hsum);
   f4_init = bkg4nb/mcsumnb;
	std::cout<<"bkg4 nb = "<<bkg4nb<<" f4_init = "<<f4_init<<endl;
	// sig omegam
	signb=getentriesfit(hThreepiIM_THREEPIGAM); 
	//signb=hThreepiIM_THREEPIGAM->GetEntries();
	f0_init = signb/mcsumnb;
	std::cout<<"sig nb = "<<signb<<" f0_init = "<<f0_init<<endl;
	RooDataHist homegam("homegam","homegam",x,Import(*hThreepiIM_THREEPIGAM)); 
	RooHistPdf homegampdf("homegampdf","homegampdf",x,homegam,0) ;	
   //homegampdf.plotOn(frame,Name("omegam_MC"),LineStyle(kSolid),LineColor(4));
   // bkg1 omega pi0
   bkg1nb=getentriesfit(hThreepiIM_OMEGAPI);
   f1_init = bkg1nb/mcsumnb;
	std::cout<<"bkg1 nb = "<<bkg1nb<<" f1_init = "<<f1_init<<endl;
   RooDataHist homegapi0("homegapi0","homegapi0",x,Import(*hThreepiIM_OMEGAPI)); 
	RooHistPdf homegapi0pdf("homegapi0pdf","homegapi0pdf",x,homegapi0,0) ;	
   //homegapi0pdf.plotOn(frame,Name("omegapi0_MC"),LineStyle(kSolid),LineColor(7));
   // bkg2 eta gamma
   bkg2nb=getentriesfit(hThreepiIM_ETAGAM);
   f2_init = bkg2nb/mcsumnb;
	std::cout<<"bkg2 nb = "<<bkg2nb<<" f2_init = "<<f2_init<<endl;
   RooDataHist hetagam("hetagam","hetagam",x,Import(*hThreepiIM_ETAGAM)); 
	RooHistPdf hetagampdf("hetagampdf","hetagampdf",x,hetagam,0) ;	
   //hetagampdf.plotOn(frame,Name("etagam_MC"),LineStyle(kSolid),LineColor(3));
   // bkg3 ksl
   bkg3nb=getentriesfit(hThreepiIM_KSL);
   f3_init = bkg3nb/mcsumnb;
	std::cout<<"bkg3 nb = "<<bkg3nb<<" f3_init = "<<f3_init<<endl;
   RooDataHist hksl("hksl","hksl",x,Import(*hThreepiIM_KSL)); 
	RooHistPdf hkslpdf("hkslpdf","hkslpdf",x,hksl,0) ;	
	//RooKeysPdf hkslpdf("hkslpdf", "hkslpdf", x, hksl, RooKeysPdf::MirrorBoth, 1);
   hkslpdf.plotOn(frame,Name("ksl_MC"),LineStyle(kSolid),LineColor(15));
   
   // get model
   RooRealVar f0("f0","",0.1,0.,1.);
	RooRealVar f1("f1","",0.1,0.,1.);
	RooRealVar f2("f2","",0.1,0.,1.);
	RooRealVar f3("f3","",0.1,0.,1.);
	
   RooAddPdf model("model","model",RooArgList(homegampdf,homegapi0pdf,hetagampdf,hkslpdf,bkgsumpdf),RooArgList(f0,f1,f2,f3));
   model.plotOn(frame,Name("model"));
   
   // fit
   //model.fitTo(data);
   
   // Draw all frames on a canvas
   TCanvas* c = new TCanvas("models_c","models",800,800) ;
   c->Divide(1) ;
   c->cd(1); 
   //hThreepiIM_THREEPIGAM->Draw();
   gPad->SetLeftMargin(0.15) ; frame->GetYaxis()->SetTitleOffset(1.4); frame->Draw();
}
