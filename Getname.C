const int NbTree = 8, NbVar = 3;

Int_t mctype = 0;
Double_t IMthreepi = 0., Eisr = 0.;

TString gettreename(Int_t index) {
	TString myArr[NbTree] = {"OMEGAPI","KPM","KSL","THREEPIGAM", "THREEPI", "ETAGAM", "BKGSUM1", "BKGSUM2"}; 
	
	TString st = myArr[index]; 
	return st;
}

TString getbraname(Int_t index) {
	TString myArr[NbVar] = {"mctype","IMthreepi","Eisr"}; 
	
	TString st = myArr[index]; 
	return st;
}


void Getname() {
	TString a = gettreename(0);
	//std::cout<<a<<endl; 
	
	
}


