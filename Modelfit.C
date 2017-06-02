#include "Getname.C"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"

gSystem->Load("libRooFit");
using namespace std;
using namespace RooFit;

void Modelfit() {
	// get tree name
	TString Data = gettreename(10);// data
	TString Sig = gettreename(3);// omega gamma
	TString Bkg1 = gettreename(0);// omega pi0
	TString Bkg2 = gettreename(2);// KSL
	TString Bkg4 = gettreename(5);// eta gamma
	//std::cout<<Sig<<endl;
	// get root file
	TFile *findFile = new TFile("./ROOT/TREE_"+cutname[modpos]+".root","READ");
	// declear variable
	RooRealVar x("ThreepiIM","ThreepiIM",650,910);
	// get MC & DATA sample
	TTree *TData = (TTree*)findFile->Get("T"+Data+"_Pre"); // data
	TTree *TThreePiGam = (TTree*)findFile->Get("T"+Sig+"_Pre"); // signal omega gamma
	TTree *TOmegaPi = (TTree*)findFile->Get("T"+Bkg1+"_Pre"); // bkg1 omega pi0
	TTree *TKSL = (TTree*)findFile->Get("T"+Bkg2+"_Pre"); // bkg2 ksl
	TTree *TEtaGam = (TTree*)findFile->Get("T"+Bkg4+"_Pre"); // bkg4 eta gamma
	// get pdfs
	// sig pdf
	RooDataSet data("data","data",RooArgSet(x),Import(*TData));
	RooDataSet sigsample("sigsample","sigsample",RooArgSet(x),Import(*TThreePiGam));
	RooKeysPdf sigpdf("sigpdf", "sigpdf", x, sigsample, RooKeysPdf::MirrorBoth, 1);
	// bkg1 pdf
	RooDataSet bkg1sample("bkg1sample","bkg1sample",RooArgSet(x),Import(*TOmegaPi));
	RooKeysPdf bkg1pdf("bkg1pdf", "bkg1pdf", x, bkg1sample, RooKeysPdf::MirrorBoth, 1);
	// bkg2 pdf
	RooDataSet bkg2sample("bkg2sample","bkg2sample",RooArgSet(x),Import(*TKSL));
	RooKeysPdf bkg2pdf("bkg2pdf", "bkg2pdf", x, bkg2sample, RooKeysPdf::MirrorBoth, 1);
	// bkg3 pdf
	// plynomial
	/*RooRealVar c0("c0","coefficient #0", 0.1,-5.,5.); 
	RooRealVar c1("c1","coefficient #1", 0.1,-5.,5.); 
	RooRealVar c2("c2","coefficient #2", -0.1,-5.,5.); 
	RooChebychev bkg3pdf("bkg3pdf","bkg3pdf",x,RooArgList(c0,c1,c2)); */
	
	RooRealVar argpar("argpar","argus shape parameter",-5.0,-100.,-1.) ; 
	RooArgusBG bkg3pdf("bkg3pdf","bkg3pdf",x,RooConst(900),argpar);
	// bkg4 pdf
	RooDataSet bkg4sample("bkg4sample","bkg4sample",RooArgSet(x),Import(*TEtaGam));
	RooKeysPdf bkg4pdf("bkg4pdf", "bkg4pdf", x, bkg4sample, RooKeysPdf::MirrorBoth, 1); 
	// get model
	RooRealVar f0("f0","omega gamma fraction",0.3,0.,1.);
	RooRealVar f1("f1","omega pi0",0.2,0.,1.);
	RooRealVar f2("f2","ksl",0.4,0.,1.);
	RooRealVar f3("f3","argus",0.1,0.,1.);
	
	RooAddPdf model("model","model",RooArgList(sigpdf,bkg1pdf,bkg4pdf,bkg2pdf,bkg3pdf),RooArgList(f0,f1,f2,f3)); 
	//RooAddPdf model("model","model",RooArgList(sigpdf,bkg4pdf),RooArgList(f0,f2)); 
	RooPlot* frame = x.frame(); 
	data.plotOn(frame); 
	model.plotOn(frame,LineStyle(kSolid),LineColor(kRed));
	//sigpdf.plotOn(frame,LineStyle(kSolid),LineColor(4)); 
	//bkg1pdf.plotOn(frame,LineStyle(kSolid),LineColor(7)); 
	//bkg2pdf.plotOn(frame,LineStyle(kSolid),LineColor(15));
	//bkg3pdf.plotOn(frame,LineStyle(kSolid),LineColor(18));
	//bkg4pdf.plotOn(frame,LineStyle(kSolid),LineColor(kGreen));
	//model.Print("t"); // print structure of the model
	// fit
	model.fitTo(data);
	model.Print("t"); 
	// Draw all frames on a canvas
   TCanvas* c = new TCanvas("IMfit","IMfit",800,400) ;
   c->Divide(1) ;
   c->cd(1) ; gPad->SetLeftMargin(0.15) ; frame->GetYaxis()->SetTitleOffset(1.6); frame->Draw();
}
