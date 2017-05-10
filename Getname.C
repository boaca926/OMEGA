const int NbTree = 11, NbVar = 7, NbCut = 3, NbMode = 4, scale = 6;
const int NbHist = 100, bin_IM = 100, bin_TOF = 400;
const double xmin_IM = 0., xmax_IM = 100.;
const double xmin_TOF = -20., xmax_TOF = 20.;
const double chi2cut = 20., tofcut1 = -0.7, tofcut2=-1.;
const double k=-5.;
const double Cutlist_std[NbCut] = {chi2cut, tofcut1, tofcut2};
const double cutstep_std[NbCut] ={2., 0.5, 5.0};
const int CUTTAG = 1; // 0 disable cut
const int colorid[NbTree] = {7, 46, 15, 4, 6, 3, 20, 20, 2, 5, 1};
const TString cutname[NbCut] = {"Chi2Cut","tofcut1","tofcut2"};
const TString modname[NbMode] = {"RhoPi","QED","DATA","AllPhys"};

// specify modification of cut values
// modpos = 0: chi2cut
// modpos = 1: tofcut1
const int modpos = 2; // chi2 loop over 2-102, nbstep=25, chicut = 52
const int nbstep = 1; // nbstep=0 give standard cut value, number of cut modification = 2nstep+1
const double step = cutstep_std[modpos]; 
const double lb = Cutlist_std[modpos]-step*nbstep, upb = Cutlist_std[modpos]+step*nbstep;


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
	TString myArr[NbVar] = {"mctype","IMthreepi","Eisr", "chi2value", "pvalue","BestPiTime","BestETime"}; 
	
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

Int_t getcutype(Double_t chi2value, Double_t cutlist[]) {
	//cout<<cutlist[0]<<endl;
	Int_t Type = 0;
	Int_t type[1] = {0};
	
	if (chi2value < cutlist[0]) {
		type[0] = 1;
	}
	else {
		type[0] = 0;
	}
	
	if (type[0]) {
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


