const int NbTree = 11, NbVar = 5, NbCut = 1, NbMode = 4, scale = 6;
const int NbHist = 100, bin = 100;
const double xmin_IM = 0., xmax_IM = 100.;
const double Chi2cut_std = 20.;
const double Chi2cut = 50.;
const double Cutlist[NbCut] = {Chi2cut};
const double Cutlist_std[NbCut] = {Chi2cut_std};
const int CUTTAG = 1; // 0 disable cut
const int colorid[NbTree] = {7, 46, 15, 4, 6, 3, 20, 20, 2, 5, 1};
const TString modname[NbMode] = {"RhoPi","QED","DATA","AllPhys"};
const TString cutname[NbCut] = {"Chi2Cut"};

TString gettreename(Int_t index) {
	TString myArr[NbTree] = {"OMEGAPI","KPM","KSL","THREEPIGAM", "THREEPI", "ETAGAM", "BKGSUM1", "BKGSUM2", "MCSUM", "EEG", "DATA"}; 
	
	TString st = myArr[index]; 
	return st;
}

TString getbraname(Int_t index) {
	TString myArr[NbVar] = {"mctype","IMthreepi","Eisr", "chi2value", "pvalue"}; 
	
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

void Getname() {
	TString a = gettreename(0);
	//std::cout<<a<<endl; 
	//Int_t type_temp=0;
	//type_temp=getcutype(Cutlist_std[]);
	//cout<<type_temp<<endl;
	
}


