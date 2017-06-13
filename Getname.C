const double omegmass = 782., masswidth = 8.5;
const double p0IMwidth = 2.05, threepiIMwidth = 1.945;
const double Resolu[2] = {threepiIMwidth, p0IMwidth}; 
const int NbTree = 12, NbVar = 23, NbCut = 9, NbMode = 4, scale = 6, scale_width = 14;
const double xmin = 0., xmin_Chi2 = 0., xmin_TOF = -10., xmin_DeltaE = -800., xmin_Tracksum = 10000., xmin_pi0IM = 100, xmin_pionPsum = 120., xmin_Mggdiffmin = -100.;
const double xmax = 1000., xmax_Chi2 = 1000., xmax_TOF = 10., xmax_DeltaE = 200., xmax_Tracksum = 600., xmax_pi0IM = 170., xmax_pionPsum = 520., xmax_Mggdiffmin = 100.;
//const double xmin_IM = omegmass-scale_width*masswidth, xmax_IM = omegmass+scale_width*masswidth;
const double xmin_IM = 450., xmax_IM =910.;
const int NbHist = 100, bin = 1000, bin_Chi2 = 50, bin_TOF = 400, bin_DeltaE = 1000, bin_Tracksum = 500, bin_pi0IM = 100, bin_IM = 155, bin_pionPsum = 400, bin_Mggdiffmin = 100;
const double binscale[1]={2.5};
const int bin_fit = (xmax_IM-xmin_IM)/(binscale[0]*Resolu[0]);
const double chi2cut = 30., tofcut1 = -0.5, tofcut2=4., deltaEcut=-215., Emaxcut=320., deltaPi0IM=4*p0IMwidth, delta3piIM=scale_width*masswidth, xmin1_IM = 450., xmax1_IM = 670.;
const double k=-5.;
const double Cutlist_std[NbCut] = {chi2cut, tofcut1, tofcut2, deltaEcut, Emaxcut, deltaPi0IM, delta3piIM, xmin_IM, xmax_IM};
const double cutstep_std[NbCut] ={2., 0.2, 1., 4., 1., p0IMwidth, threepiIMwidth, 0.,0.};
const int CUTTAG = 1; // 0 disable cut
const int colorid[NbTree] = {7, 46, 15, 4, 6, 3, 20, 20, 2, 5, 1, 20};
const TString cutname[NbCut] = {"Chi2Cut","tofcut1","tofcut2","DeltaEcut","Emaxcut","DeltaPi0IM","Delta3piIM","",""};
const TString xname[NbCut] = {"#chi^{2} cut","#Deltat_{e^{#pm}} cut","#Delta_{#pi^{#pm}} cut", "#deltaE cut", "Emax cut", "Pi0IM cut", "threePiIM cut", "",""};
const TString modname[NbMode] = {"RhoPi","QED","DATA","AllPhys"};
const double sqrtS = 1.019; // center of mass energy
const double me = 0.511*0.001; // mass of electron
const double pi=TMath::Pi();
const double theta0 = 23*pi/180; // polar angle
const double m_omega = 782.; // MeV
double C = TMath::Power(2*me/sqrtS,2);
const double alpha = 1./137; // fine structure constant
const double alphapi = alpha/pi;
// specify modification of cut values
// modpos = 0: chi2cut
// modpos = 1: tofcut1
// modpos = 2: tofcut2
// modpos = 3: deltaEcut
// modpos = 4: Emaxcut
const int modpos = 4; // chi2 loop over 2-102, nbstep=25, chicut = 52
const int nbstep = 0; // nbstep=0 give standard cut value, number of cut modification = 2nstep+1
const double step = cutstep_std[modpos]; 

Double_t getentriesfit(TH1D *h) {
	Double_t sum_temp=0, entry_temp=0;
	for (Int_t i =1;i<=h->GetNbinsX();i++) {
		sum_temp=entry_temp+h->GetBinContent(i);
		entry_temp=sum_temp;
	}
	return sum_temp;
}

void format_h(TH1D* h, Int_t fillcolor, Int_t fillstyle, Int_t width) {
	h->SetLineWidth(width);
	h->SetFillStyle(fillstyle);
	h->SetLineColor(fillcolor);
}

TString gettreename(Int_t index) {
	TString myArr[NbTree] = {"OMEGAPI","KPM","KSL","THREEPIGAM", "THREEPI", "ETAGAM", "BKGSUM1", "BKGSUM2", "MCSUM", "EEG", "DATA","BKGSUM"}; 
	
	TString st = myArr[index]; 
	return st;
}

TString getbraname(Int_t index) {
	TString myArr[NbVar] = {"mctype","IMthreepi","Eisr", "chi2value", "pvalue","BestPiTime","BestETime","DeltaE","tracksum","ThreepiIM","IMdiff","ThreepiIM_impv","Emaxprompt",
"bestpiphoton1Ekinfit","bestpiphoton2Ekinfit","ISRE","ISR_impv","pionphotonEsum","ThreepiIM_nofit","Mggdiffmin",
"Pi0IM","ThreepiIM_MC","ThreepiIM_rec"}; 
	
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

Int_t getcutype(Double_t chi2value, Double_t bestETime, Double_t bestPiTime, Double_t deltaE, Double_t Emax, Double_t deltaPi0IM, Double_t threePiIM, Double_t cutlist[]) {
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
	// Emax
	if (Emax < cutlist[4]) {
		type[4] = 1;
	}
	else {
		type[4] = 0;
	}
	// Pi0IM
	if (TMath::Abs(deltaPi0IM) < cutlist[5] ) {
		type[5] = 1;
	}
	else {
		type[5] = 0;
	}
	//
	//if (TMath::Abs(threePiIM-omegmass) < cutlist[6]) {
	if (threePiIM > cutlist[7] && threePiIM < cutlist[8]) {
		type[6] = 1;
	}
	else {
		type[6] = 0;
	}
	// all cuts
	if (type[0] && type[1] && type[2] && type[3]) {
	//if (!type[0] && type[1] && type[2] && type[3] && type[4]) {// get ksl fraction
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


