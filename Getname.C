const int NbTree = 11, NbVar = 17, NbCut = 4, NbMode = 4, scale = 6;
const int NbHist = 100, bin_Chi2 = 100, bin_TOF = 400, bin_DeltaE = 1000, bin_Tracksum = 1000, bin_IM = 110;
const double xmin_Chi2 = 0., xmin_TOF = -10., xmax_DeltaE = 200., xmin_Tracksum = 0., xmin_IM = 0.;
const double xmax_Chi2 = 100., xmax_TOF = 10., xmin_DeltaE = -800., xmax_Tracksum = 1000., xmax_IM = 1100;
const double chi2cut = 32., tofcut1 = -0.5, tofcut2=4., deltaEcut=-215.;
const double k=-5.;
const double Cutlist_std[NbCut] = {chi2cut, tofcut1, tofcut2, deltaEcut};
const double cutstep_std[NbCut] ={2., 0.2, 1., 4.};
const int CUTTAG = 1; // 0 disable cut
const int colorid[NbTree] = {7, 46, 15, 4, 6, 3, 20, 20, 2, 5, 1};
const TString cutname[NbCut] = {"Chi2Cut","tofcut1","tofcut2","DeltaEcut"};
const TString xname[NbCut] = {"#chi^{2} cut","#Deltat_{e^{#pm}} cut","#Delta_{#pi^{#pm}} cut", "#deltaE cut"};
const TString modname[NbMode] = {"RhoPi","QED","DATA","AllPhys"};

// specify modification of cut values
// modpos = 0: chi2cut
// modpos = 1: tofcut1
// modpos = 2: tofcut2
// modpos = 3: deltaEcut
const int modpos = 0; // chi2 loop over 2-102, nbstep=25, chicut = 52
const int nbstep = 0; // nbstep=0 give standard cut value, number of cut modification = 2nstep+1
const double step = cutstep_std[modpos]; 



void format_h(TH1D* h, Int_t fillcolor, Int_t fillstyle, Int_t width) {
	h->SetLineWidth(width);
	h->SetFillStyle(fillstyle);
	h->SetLineColor(fillcolor);
}

TString gettreename(Int_t index) {
	TString myArr[NbTree] = {"OMEGAPI","KPM","KSL","THREEPIGAM", "THREEPI", "ETAGAM", "BKGSUM1", "BKGSUM2", "MCSUM", "EEG", "DATA"}; 
	
	TString st = myArr[index]; 
	return st;
}

TString getbraname(Int_t index) {
	TString myArr[NbVar] = {"mctype","IMthreepi","Eisr", "chi2value", "pvalue","BestPiTime","BestETime","DeltaE","tracksum","ThreepiIM","IMdiff","ThreepiIM_impv","Emaxprompt","bestpiphoton1Ekinfit","bestpiphoton2Ekinfit","ISRE","ISR_impv"}; 
	
	TString st = myArr[index]; 
	return st;
}

Double_t getbinwidth(TH1D* h) {
  Int_t binsize=0;
  Double_t width=0.;
  Double_t xmax=0., xmin=0.;
  xmax = h->GetXaxis()->GetXmax(); //cout<<xmax<<endl;
	xmin = h->GetXaxis()->GetXmin(); //cout<<xmin<<endl;
  binsize=h->GetNbinsX(); //cout<<binsize<<endl;
  width=(xmax-xmin)/binsize; //cout<<width<<endl;
   
  return width;
}

void normlizehisto(TH1D* h, TH1D* hh) {
	Int_t binsize=0, binsize1=0;
	Double_t content=0., xmax=0., xmin=0.;
	Double_t totalev=0., binwidth=0., scalefactor=0.;

	xmax = hh->GetXaxis()->GetXmax(); //cout<<xmax<<endl;
	xmin = hh->GetXaxis()->GetXmin(); //cout<<xmin<<endl;
	binsize=hh->GetNbinsX(); //cout<<binsize<<endl;
	binwidth = (xmax-xmin)/binsize; //cout<<binwidth<<endl;
	totalev=hh->GetEntries(); //cout<<totalev<<endl;
	scalefactor=totalev*binwidth; //cout<<scalefactor<<endl;
	
	binsize1=h->GetNbinsX();
	for (Int_t index=1; index<binsize1+1;index++) {
		content=h->GetBinContent(index)/scalefactor; //cout<<content<<endl;
		h->SetBinContent(index,content); //cout<<h->GetBinContent(index)<<endl;
	}
}

Int_t getcutype(Double_t chi2value, Double_t bestETime, Double_t bestPiTime, Double_t deltaE, Double_t cutlist[]) {
	//cout<<bestETime<<endl;
	Int_t Type = 0;
	Int_t type[NbCut];
	for (int i=0;i<NbCut;i++) {
		type[i]=0.;
	}
	// chi2 cut
	if (chi2value < cutlist[0]) {
		type[0] = 1;
	}
	else {
		type[0] = 0;
	}
	// tof cut1
	if (bestETime < cutlist[1]) {
		type[1] = 1;
	}
	else {
		type[1] = 0;
	}
	// tof cut2
	if (bestETime < k*bestPiTime+cutlist[2]) {
		type[2] = 1;
	}
	else {
		type[2] = 0;
	}
	// deltaE cut
	if (deltaE < cutlist[3]) {
		type[3] = 1;
	}
	else {
		type[3] = 0;
	}
	// all cuts
	if (type[0] && type[1] && type[2] && type[3]) {
	//if (type[modpos]) {
		Type = 1;
	}
	else {
		Type = 0;
	}
	
	return Type;
}

/*void removefiles(const char *dirname= "/home/bo/Desktop/omega/ROOT") {
	TSystemDirectory dir(dirname, dirname);
	dir.Delete();
	TList *files = dir.GetListOfFiles();
	
	if (files) {
		TSystemFile *file;
		TString fname;
		TIter next(files);
		while ((file=(TSystemFile*)next())) {
			fname = file->GetName();
			if (!file->IsDirectory()) {
				cout<<fname.Data()<<endl;
				
			}
		}
		
	}
}*/



void Getname() {
	TString a = gettreename(0);
	//std::cout<<a<<endl; 
	
	
}


