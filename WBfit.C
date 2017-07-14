#include "Getname.C"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
#include "gethisto.C"
#include "CROSS.C"

gSystem->Load("libRooFit");
using namespace std;
using namespace RooFit;

void WBfit() {
	// get histo
	double threepiIMreso = Resolu[0];
	//double subrange1 = 740., subrange2 = 820.;
	double subrange1 = xmin_IM, subrange2 = xmax_IM;
	const int stepnb = 0;
	std::cout<<"threepi IM resolution = "<<threepiIMreso<<endl;
	TFile *f = new TFile("./ROOT/HISTOS1.root","READ");
	TH1D *hcross = (TH1D*)f->Get("HCross");
	RooRealVar m( "m", "three pion invariant mass", xmin_IM,xmax_IM);
	RooRealVar x( "x", "", -10.,10.);
	x.setRange("intrange",xmin_IM,xmax_IM);
	
	RooDataHist data("data","data",m,Import(*hcross));
	
   // Breit-Wigner
   RooRealVar m0( "m0", "m0", 782.65, 750.,800.);
   RooRealVar width( "width", "width", 8.49,5.,10. );
   RooBreitWigner bw( "bw", "bw", m, m0, width );
   
   // Detector response function
   RooRealVar mg("mg","mg",0.,0.,10.);
   RooRealVar sg("sg","sg",2.,0.,10.) ;
	RooGaussian gauss("gauss","gauss",m,mg,sg);
	
	RooRealVar mg1("mg1","mg1",782.65,700.,800.);
   RooRealVar sg1("sg1","sg1",2.,0.,100.) ;
	RooGaussian gauss1("gauss1","gauss1",m,mg1,sg1);
	
	// Define sampling frequency
	//m.setBins(10000,"fft") ;
		
	// Construct convolution
	RooRealVar frac("f","fraction",0.5,0.,1.); 
	 
	RooFFTConvPdf bwg("bwg","bwg",m,bw,gauss); 
   RooAddPdf model("model","model",RooArgList(bw,gauss1),frac);
   // systematics
   const int STEP=stepnb*2+1;
   const double step=0.;
   double lb1 = subrange1-step*nbstep, upb1 = subrange2+step*nbstep;
   //for (int i=0;i<STEP;i++) {
   	//std::cout<<"=================================="<<endl;
   	//std::cout<<"fit range = ["<<lb1<<","<<upb1<<"]"<<endl;
   	RooFitResult* rf = bwg.fitTo(data,Range(subrange1,subrange2));   	
   	//lb1+=step; 
   //}

	   
   RooRealVar *var = (RooRealVar*)bwg.getObservables(RooArgSet(m))->first();
   
   // normlized TF1 function of fit model bwg
   TF1* func = (TF1*) bwg.asTF(RooArgList(m), RooArgList(m0,mg,sg,width),RooArgList(m));
   
   // get binwidth
	TAxis* axis_hhdata = hcross->GetXaxis();
	int BINSIZE = hcross->GetNbinsX();
	int const binsize = BINSIZE; 
	double binwidth = (xmax_IM-xmin_IM)/binsize;
	std::cout<<"binsize ="<<binsize<<", binwidth = "<<binwidth<<endl;
	double m_bin = 0., cross_bin = 0.;
	double m_list[binsize], cross_list[binsize];
   for (int i = 1;i<=binsize;i++) {
   	var->setVal(hcross->GetBinCenter(i));
   	m_bin = var->getVal(); m_list[i] = m_bin;
   	cross_bin = bwg.getVal(); 
   	cross_list[i] = func(m_bin);
   	//std::cout<<"Bin ["<<i<<"]\n"<<endl;
   	std::cout<<"mvalue ="<<m_bin<<", checked mvalue = "<<hcross->GetBinCenter(i)<<endl;
   	//std::cout<<"pdf value = "<<cross_bin<<", checked value ="<<func(m_bin)<<endl;
   	
   }
   
   auto gf= new TGraph(binsize,m_list,cross_list); 
   
   RooPlot* frame = m.frame();
	data.plotOn(frame);
	//model.plotOn(frame,Name("bw"),Components("bw"),LineStyle(kSolid),LineColor(kRed));
	//model.plotOn(frame,Name("gauss1"),Components("gauss1"),LineStyle(kDashed),LineColor(7));
	//gauss.plotOn(frame);
	bwg.plotOn(frame,Name("bwg"));
	frame->GetXaxis()->SetRangeUser(subrange1,subrange2);	
	frame->Draw("Same");
	
	
	
	Double_t chi2 = frame->chiSquare(4);
   std::cout<<"chi2 value = "<<chi2<<", ndf = "<<4<<endl;
   
   TCanvas* c = new TCanvas("c","WBfit",800,400);
	c->Divide(1); 
   c->cd(1); 
   hcross->Draw();
   gf->SetMarkerSize(0.4);
   gf->SetMarkerStyle(21);
   gf->Draw("P Same");
   
   
   
   /*RooPlot* frame1 = m.frame();
   TCanvas* c1 = new TCanvas("c1","gausss",800,400);
	c1->Divide(1); 
   c1->cd(1);
   bw.plotOn(frame1);
   frame1->Draw();*/
}
