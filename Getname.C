const int NbTree = 11, NbVar = 5, NbCut = 1, NbMode = 4, scale = 6;
const int NbHist = 100, bin = 100;
const double xmin_IM = 0., xmax_IM = 100.;
const double chi2cut = 20.;
const int CUTTAG[NbCut] = {0}; // 0 disable cut
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

void drawline(Double_t a, Double_t b, Double_t c, Double_t d, Int_t color) {
	TLine *l = new TLine(a,b,c,d);
	l->SetLineColor(color);
	l->SetLineWidth(2);
	l->SetLineStyle(3); // 1=solid, 2=dash, 3=dash-dot, 4=dot-dot
	l->Draw("Same");
}

void legtextsize(TLegend* l, Double_t size) {
  for(int i=0 ; i<l->GetListOfPrimitives()->GetSize() ; i++) {
    TLegendEntry *header = (TLegendEntry*)l->GetListOfPrimitives()->At(i);
    header->SetTextSize(size);
  }      
}

void Getname() {
	TString a = gettreename(0);
	//std::cout<<a<<endl; 
	
	
}


