const int NbTree = 10, NbVar = 5, NbCut = 2, NbMode = 4;
const double chi2cut = 20.;
const int CUTTAG[NbMode] = {1,1,1,1};
const TString modname[NbMode] = {"RhoPi","AllPhys","QED","DATA"};

TString gettreename(Int_t index) {
	TString myArr[NbTree] = {"OMEGAPI","KPM","KSL","THREEPIGAM", "THREEPI", "ETAGAM", "BKGSUM1", "BKGSUM2", "MCSUM", "ALLCHAIN"}; 
	
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


