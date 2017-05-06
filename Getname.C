const int NbTree = 11, NbVar = 5, NbCut = 1, NbMode = 4, scale = 6;
const int NbHist = 100, bin = 100;
const double xmin_IM = 0., xmax_IM = 100.;
const double chi2cut = 20.;
const int CUTTAG[NbCut] = {1}; 
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


void Getname() {
	TString a = gettreename(0);
	//std::cout<<a<<endl; 
	
	
}


