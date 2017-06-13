#include "Getname.C"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
#include "gethisto.C"

gSystem->Load("libRooFit");
using namespace std;
using namespace RooFit;

void cross(RooDataHist* h, int bin) {
	TH1D* hhdata = h->createHistogram("ThreepiIM",bin);
	double binsize=hhdata->GetNbinsX();
	std::cout<<"binsize = "<<binsize<<endl;
	hhdata->Draw();
}

void roofit_eta() {
	Double_t threepiIM = 0.;
	TString SThreepiIM = getbraname(9);// 
	// get root file
	TFile *findFile = new TFile("./ROOT/TREE_cutted.root","READ");
	// get trees 
	TString Omegpi = gettreename(0);// omega pi0
	TString Ksl = gettreename(2);// KSL
	TString Omegam = gettreename(3);// omega gamma
	TString Etagam = gettreename(5);// eta gamma
	TString Data = gettreename(10);// data
	TString MCrest = gettreename(11);// mc rest = ksl + 
	
	TTree *TData = (TTree*)findFile->Get("T"+Data+"_Pre"); // data
	TTree *TEtagam = (TTree*)findFile->Get("T"+Etagam+"_Pre"); // etagam
	TTree *TKsl = (TTree*)findFile->Get("T"+Ksl+"_Pre"); // ksl
	TTree *TOmegpi = (TTree*)findFile->Get("T"+Omegpi+"_Pre");// omegapi
	TTree *TMCrest = (TTree*)findFile->Get("T"+MCrest+"_Pre"); // MCrest
	TTree *TOmegam = (TTree*)findFile->Get("T"+Omegam+"_Pre"); // omega gamma
	
	TCollection* treelist = new TList;
	treelist->Add(TData);
	treelist->Add(TEtagam);
	treelist->Add(TKsl);
	treelist->Add(TOmegpi);
	treelist->Add(TMCrest);
	treelist->Add(TOmegam);
	
	TObject* treeout=0;
	TIter treeliter(treelist);
	while((treeout=treeliter.Next()) !=0) {
		//treeout->Print();
		TTree* tree_temp=dynamic_cast<TTree*>(treeout);
		tree_temp->SetBranchAddress(SThreepiIM,&threepiIM);
	}	
	// declear variable
	double fitcut=630;
	RooRealVar x("ThreepiIM","ThreepiIM",xmin_IM,fitcut);
	RooRealVar xx("ThreepiIM","ThreepiIM",fitcut,xmax_IM);	
	const int binnb=100;
	x.setBins(binnb); xx.setBins(binnb);
	x.setRange("window",xmin_IM,fitcut); xx.setRange("window1",fitcut,xmax_IM);
	
	// data
	
	double N_d=0, n_d=0;
	for (Int_t irow=0;irow<TData->GetEntries();irow++) {
		TData->GetEntry(irow); 
		if (threepiIM > xmin_IM && threepiIM < fitcut) {
   		N_d++;
   	}	
   	else if (threepiIM >= fitcut && threepiIM < xmax_IM) {
   		//cout<<threepiIM<<endl;
			n_d++;
		}
   }
   std::cout<<"N_d = "<<N_d<<" in range ["<<xmin_IM<<","<<fitcut<<"]"<<endl;
   std::cout<<"n_d = "<<n_d<<" in range ["<<fitcut<<","<<xmax_IM<<"]"<<endl;
	RooDataSet data("data","data",RooArgSet(x),Import(*TData));
	RooDataHist* hdata = data.binnedClone();
	RooHistPdf hdatapdf("hdatapdf","hdatapdf",x,*hdata,0);
	TH1D* hhdata = hdata->createHistogram("ThreepiIM",binnb);
	
	RooDataSet data_above("data_above","data_above",RooArgSet(xx),Import(*TData));
	
	
	// etagam	
	double N_etagam=0, fetagam_init=0;
	double n_etagam=0, ffetagam_init=0;
   for (Int_t irow=0;irow<TEtagam->GetEntries();irow++) {
   	TEtagam->GetEntry(irow); 
   	//cout<<threepiIM<<endl;
   	if (threepiIM > xmin_IM && threepiIM < fitcut) {
   		N_etagam++;
   	}	
   	else if (threepiIM >= fitcut && threepiIM < xmax_IM) {
   		n_etagam++;
   	}
   }
   fetagam_init=N_etagam/N_d; ffetagam_init=n_etagam/N_d;
   std::cout<<"N_etagam = "<<N_etagam<<", fetagam_init = "<<fetagam_init<<" in range ["<<xmin_IM<<","<<fitcut<<"]"<<endl;
   std::cout<<"n_etagam = "<<n_etagam<<", ffetagam_init = "<<ffetagam_init<<" in range ["<<fitcut<<","<<xmax_IM<<"]"<<endl;
   
   RooDataSet etagam("etagam","etagam",TEtagam,x);
   RooKeysPdf etagampdf("etagampdf", "etagampdf", x, etagam, RooKeysPdf::MirrorBoth, 1);
   
   RooDataSet etagam_above("etagam_above","etagam_above",TEtagam,xx);
   RooKeysPdf etagampdf_above("etagampdf_above", "etagampdf_above", xx, etagam_above, RooKeysPdf::MirrorBoth, 1);
   // ksl   
   double N_ksl=0, fksl_init=0;
   double n_ksl=0, ffksl_init=0;
   for (Int_t irow=0;irow<TKsl->GetEntries();irow++) {
   	TKsl->GetEntry(irow); 
   	if (threepiIM > xmin_IM && threepiIM < fitcut) {
   		N_ksl++;
   	}
   	else if (threepiIM >= fitcut && threepiIM < xmax_IM) {
   		n_ksl++;
   	}
   }
   fksl_init=N_ksl/N_d; ffksl_init=n_ksl/N_d;
   std::cout<<"N_ksl = "<<N_ksl<<", fksl_init = "<<fksl_init<<" in range ["<<xmin_IM<<","<<fitcut<<"]"<<endl;
   std::cout<<"n_ksl = "<<n_ksl<<", ffksl_init = "<<ffksl_init<<" in range ["<<fitcut<<","<<xmax_IM<<"]"<<endl;
   
   RooDataSet ksl_above("ksl_above","ksl_above",TKsl,xx);
   RooKeysPdf kslpdf_above("kslpdf_above", "kslpdf_above", xx, ksl_above, RooKeysPdf::MirrorBoth, 1);  
   
   RooDataSet ksl("ksl","ksl",TKsl,x);
   RooKeysPdf kslpdf("kslpdf", "kslpdf", x, ksl, RooKeysPdf::MirrorBoth, 1);
   // omegpi 
   double N_omegpi=0, fomegpi_init=0;
   double n_omegpi=0, ffomegpi_init=0;
   for (Int_t irow=0;irow<TOmegpi->GetEntries();irow++) {
   	TOmegpi->GetEntry(irow); 
   	if (threepiIM > xmin_IM && threepiIM < fitcut) {
   		N_omegpi++;
   	}
   	else if (threepiIM >= fitcut && threepiIM < xmax_IM) {
   		n_omegpi++;
   	}
   }
   fomegpi_init=N_omegpi/N_d; ffomegpi_init=n_omegpi/N_d;
   std::cout<<"N_omegpi = "<<N_omegpi<<", fomegpi_init = "<<fomegpi_init<<" in range ["<<xmin_IM<<","<<fitcut<<"]"<<endl;
   std::cout<<"n_omegpi = "<<n_omegpi<<", ffomegpi_init = "<<ffomegpi_init<<" in range ["<<fitcut<<","<<xmax_IM<<"]"<<endl;
   
   RooDataSet omegpi("omegpi","omegpi",TOmegpi,x);
   RooKeysPdf omegpipdf("omegpipdf", "omegpipdf", x, omegpi, RooKeysPdf::MirrorBoth, 1);
   
   RooDataSet omegpi_above("omegpi_above","omegpi_above",TOmegpi,xx);
   RooKeysPdf omegpipdf_above("omegpipdf_above", "omegpipdf_above", xx, omegpi_above, RooKeysPdf::MirrorBoth, 1);
   // omegam
   double N_omegam=0, fomegam_init=0;
   double n_omegam=0, ffomegam_init=0;
   for (Int_t irow=0;irow<TOmegam->GetEntries();irow++) {
   	TOmegam->GetEntry(irow); 
   	if (threepiIM > xmin_IM && threepiIM < fitcut) {
   		N_omegam++;
   	}
   	else if (threepiIM >= fitcut && threepiIM < xmax_IM) {
   		n_omegam++;
   	}	
   }
   fomegam_init=N_omegam/N_d; ffomegam_init=n_omegam/N_d;
   
   std::cout<<"N_omegam = "<<N_omegam<<", fomegam_init = "<<fomegam_init<<" in range ["<<xmin_IM<<","<<fitcut<<"]"<<endl;
   std::cout<<"n_omegam = "<<n_omegam<<", ffomegam_init = "<<ffomegam_init<<" in range ["<<fitcut<<","<<xmax_IM<<"]"<<endl;
   
   RooDataSet omegam("omegam","omegam",TOmegam,x);
   RooKeysPdf omegampdf("omegampdf", "omegampdf", x, omegam, RooKeysPdf::MirrorBoth, 1);
   
   RooDataSet omegam_above("omegam_above","omegam_above",TOmegam,xx);
   RooKeysPdf omegampdf_above("omegampdf_above", "omegampdf_above", xx, omegam_above, RooKeysPdf::MirrorBoth, 1);
   // mc rest   
   double N_mcrest=0, fmcrest_init=0;
   double n_mcrest=0, ffmcrest_init=0;
   for (Int_t irow=0;irow<TMCrest->GetEntries();irow++) {
   	TMCrest->GetEntry(irow); 
   	if (threepiIM > xmin_IM && threepiIM < fitcut) {
   		N_mcrest++;
   	}
   	else if (threepiIM >= fitcut && threepiIM < xmax_IM) {
   		n_mcrest++;
   	}
   } 
   fmcrest_init=N_mcrest/N_d; ffmcrest_init=n_mcrest/N_d;
   std::cout<<"N_mcrest = "<<N_mcrest<<", fmcrest_init = "<<fmcrest_init<<" in range ["<<xmin_IM<<","<<fitcut<<"]"<<endl;
   std::cout<<"n_mcrest = "<<n_mcrest<<", ffmcrest_init = "<<ffmcrest_init<<" in range ["<<fitcut<<","<<xmax_IM<<"]"<<endl;
   
   RooDataSet mcrest("mcrest","mcrest",TMCrest,x);
   RooKeysPdf mcrestpdf("mcrestpdf", "mcrestpdf", x, mcrest, RooKeysPdf::MirrorBoth, 1);
   
   RooDataSet mcrest_above("mcrest_above","mcrest_above",TMCrest,xx);
   RooKeysPdf mcrestpdf_above("mcrestpdf_above", "mcrestpdf_above", xx, mcrest_above, RooKeysPdf::MirrorBoth, 1);
   // threepi gamma
   RooRealVar a0("a0","a0",0.5,-5.,5.) ;
   RooRealVar a1("a1","a1",-0.2,-5.,5.) ;
   RooChebychev threepigampdf_above("threepigampdf_above","threepigampdf_above",xx,RooArgSet(a0,a1));
   ffthreepigam_init=1-ffmcrest_init-ffomegam_init-ffomegpi_init-ffksl_init-ffetagam_init;
   
   // constrcut model for fit in control region [xmin fitcut]
   double factor = 1.0/(fetagam_init+fksl_init+fomegpi_init+fomegam_init+fmcrest_init);
   RooRealVar fksl("fksl","ksl fraction",factor*fksl_init);
   RooRealVar fomegpi("fomegpi","omegpi fraction",factor*fomegpi_init);  
   RooRealVar fomegam("fomegam","fomegam fraction",factor*fomegam_init);  
   RooRealVar fmcrest("fmcrest","mcrest fraction",factor*fmcrest_init);
   RooRealVar sigfrac("sigfrac","sig fraction",factor*fetagam_init,0,1);
   RooAddPdf sig("sig","Signal",etagampdf,sigfrac);
	RooAddPdf bkgsum("bkgsum","bkgsum",RooArgList(kslpdf,omegpipdf,omegampdf,mcrestpdf),RooArgList(fksl,fomegpi,fomegam,fmcrest));
   //bkgfrac.setConstant(kTRUE);
   //RooRealVar f1("nsig", "nsig", 3000, 0, 20000);
   //RooRealVar f2("nbkg", "nbkg", 4000, 0, 20000);
   RooAddPdf model("model","model",RooArgList(sig,bkgsum),sigfrac);
   //RooAddPdf model("model","model", RooArgList(sig, bkgsum),  RooArgList(f1,f2));
   // first fit in control region, determine scale of etagam 
   RooFitResult* rf = model.fitTo(data,Range(xmin_IM,fitcut));
   // get fit result
   double scale_eta = 0;
   scale_eta = sigfrac.getVal()/fetagam_init;// sig fraction after fit: 0.862038
   std::cout<<"<<<<<<<<<<<<<< DETERMINED SCALE OF etagam S = "<<scale_eta<<" <<<<<<<<<<<<<<"<<endl;
   model.Print("t");
	// Draw all frames on a canvas
	RooPlot* frame = x.frame(); 
	data.plotOn(frame);
	//etagampdf.plotOn(frame,LineStyle(kSolid),LineColor(3));
	//kslpdf.plotOn(frame,LineStyle(kSolid),LineColor(15));
	//omegpipdf.plotOn(frame,LineStyle(kSolid),LineColor(7));
	//mcrestpdf.plotOn(frame,LineStyle(kSolid),LineColor(20));
	
	model.plotOn(frame,Name("model"),LineStyle(kSolid),LineColor(kRed));
	//hdatapdf.plotOn(frame,LineStyle(kSolid),LineColor(kRed),LineWidth(2));
	model.plotOn(frame,Name("sig"),Components("sig"),LineStyle(kSolid),LineColor(3));
	model.plotOn(frame,Name("omegpipdf"),Components("omegpipdf"),LineStyle(kSolid),LineColor(7));
	model.plotOn(frame,Name("kslpdf"),Components("kslpdf"),LineStyle(kSolid),LineColor(15));
	model.plotOn(frame,Name("omegampdf"),Components("omegampdf"),LineStyle(kSolid),LineColor(4));
	model.plotOn(frame,Name("mcrestpdf"),Components("mcrestpdf"),LineStyle(kSolid),LineColor(20));
	model.plotOn(frame,Name("bkgsum"),Components("bkgsum"),LineStyle(kSolid),LineColor(1));
	
	// constrcut model for fit in control region [fitcut xmax]
	RooRealVar ffksl("ffksl","ksl fraction",ffksl_init);
	RooRealVar ffomegpi("ffomegpi","omegpi fraction",ffomegpi_init);  
   RooRealVar ffomegam("ffomegam","fomegam fraction",ffomegam_init);  
   RooRealVar ffmcrest("ffmcrest","mcrest fraction",ffmcrest_init);
   RooRealVar ffthreepigam("ffthreepigam","threepigam fraction",ffthreepigam_init,0,1);
   RooRealVar ffetagam("ffetagam","sig fraction",ffetagam_init);
   RooAddPdf sig_above("sig_above","signal_above",threepigampdf_above,ffthreepigam);
   RooAddPdf bkgsum_above("bkgsum_above","bkgsum_above",RooArgList(kslpdf_above,omegpipdf_above,omegampdf_above,mcrestpdf_above,etagampdf_above),RooArgList(ffksl,ffomegpi,ffomegam,ffmcrest,ffetagam));
   RooAddPdf model_above("model_above","model_above",RooArgList(sig_above,bkgsum_above),ffthreepigam);
   //
   RooFitResult* rrf = model_above.fitTo(data_above,Range(fitcut,xmax_IM));
	//
	RooPlot* frame_above = xx.frame();
	data_above.plotOn(frame_above);
	/*etagampdf_above.plotOn(frame_above,LineStyle(kSolid),LineColor(3));
	kslpdf_above.plotOn(frame_above,LineStyle(kSolid),LineColor(15));
	omegpipdf_above.plotOn(frame_above,LineStyle(kSolid),LineColor(7));
	omegampdf_above.plotOn(frame_above,LineStyle(kSolid),LineColor(4));
	mcrestpdf_above.plotOn(frame_above,LineStyle(kSolid),LineColor(20));
	threepigampdf_above.plotOn(frame_above,LineStyle(kSolid),LineColor(6));*/
	
	model_above.plotOn(frame_above,Name("model_above"),LineStyle(kSolid),LineColor(kRed));	
	model_above.plotOn(frame_above,Name("etagampdf_above"),Components("etagampdf_above"),LineStyle(kSolid),LineColor(3));
	model_above.plotOn(frame_above,Name("kslpdf_above"),Components("kslpdf_above"),LineStyle(kSolid),LineColor(15));
	model_above.plotOn(frame_above,Name("omegpipdf_above"),Components("omegpipdf_above"),LineStyle(kSolid),LineColor(7));
	model_above.plotOn(frame_above,Name("omegampdf_above"),Components("omegampdf_above"),LineStyle(kSolid),LineColor(4));
	model_above.plotOn(frame_above,Name("mcrestpdf_above"),Components("mcrestpdf_above"),LineStyle(kSolid),LineColor(20));
	//model_above.plotOn(frame_above,Name("bkgsum_above"),Components("bkgsum_above"),LineStyle(kSolid),LineColor(1));
	model_above.plotOn(frame_above,Name("sig_above"),Components("sig_above"),LineStyle(kSolid),LineColor(6));
	
	TCanvas* c = new TCanvas("IMfit","IMfit",800,400) ;
	c->Divide(2) ;
   c->cd(1);   
   Double_t ymax = hhdata->GetMaximum();
   gPad->SetLeftMargin(0.15); 
   frame->GetYaxis()->SetRangeUser(0.1,ymax*1.2);
   frame->GetYaxis()->SetTitleOffset(1.6); 
   frame->GetXaxis()->SetTitle("M(3#pi) [MeV]");
   frame->Draw();
   gPad->SetLogy();
   
   c->cd(2); 
	frame_above->Draw();
	
}
