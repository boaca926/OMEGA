#include "Getname.C"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
#include "gethisto.C"

gSystem->Load("libRooFit");
using namespace std;
using namespace RooFit;

void Convtest() {
	// get histo
	double threepiIMreso = Resolu[0];
	double subrange1 = 700., subrange2 = 820.;
	std::cout<<"threepi IM resolution = "<<threepiIMreso<<endl;
	TFile *f = new TFile("./ROOT/HISTOS1.root","READ");
	TH1D *h = (TH1D*)f->Get("HCross_bin");
	//
	RooRealVar m( "m", "three pion invariant mass", xmin_IM,xmax_IM);
	RooRealVar x( "x", "", -10.,10.);
	
	RooDataHist data("data","data",m,Import(*h));
	
	// Breit-Wigner
   RooRealVar m0( "m0", "m0", 782.65, 750.,800.);
   RooRealVar width( "width", "width", 8.49,5.,10. );
   RooBreitWigner bw( "bw", "bw", m, m0, width );
   
   // Detector response function
   RooRealVar mg("mg","mg",0.,0.,10.);
   RooRealVar sg("sg","sg",threepiIMreso,0.,5.);
	RooGaussian gauss("gauss","gauss",m,mg,sg);
	
	m.setBins(1000000,"fft");
	RooFFTConvPdf bwg("bwg","bwg",m,bw,gauss);
	
	RooFitResult* rf = bwg.fitTo(data,Range(subrange1,subrange2)); 
   
   RooPlot* frame = m.frame();
   data.plotOn(frame);
   bwg.plotOn(frame);
   bw.plotOn(frame,LineStyle(kDashed)) ;
   frame->Draw();

}
