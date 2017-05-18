#include "Getname.C"
#include <iostream>
#include <string>

using namespace std;

Double_t tree(double list[], int index) 
{
	
	for (int i=0;i<NbCut;i++) {
		std::cout<<cutname[i]<<": "<<list[i]<<endl;
	}
	
	TString str_index; 
	str_index.Form("%d",index); 
	// return str_index.Data);
	//std::cout<<str_index<<endl;
	Double_t result[2] ={0., 0.};
	// initialize variables
	Int_t mctype = 0;
	Int_t CUTYPE = 0;
	Double_t threepiIM_MC = 0.;
	Double_t isrE_MC = 0.;
	Double_t chi2value = 0.;
	Double_t bestPiTime = 0.;
	Double_t bestETime = 0.;
	Double_t deltaE = 0.;
	Double_t tracksum = 0.;
	Double_t threepiIM = 0.;
	Double_t IMdiff = 0.;
	Double_t threepiIM_impv = 0.;
	Double_t Emaxprompt = 0.;
	Double_t bestpiphoton1Ekinfit = 0.;
	Double_t bestpiphoton2Ekinfit = 0.;
	Double_t isrE = 0.;
	Double_t isrE_impv  = 0.;
	Double_t pionphotonEsum = 0.;
	Double_t threepiIM_nofit = 0.;
	Double_t isrErec_nofit = 0.;
	Double_t isrE_nofit = 0.;
	Double_t diffisrE = 0.;
	// tree names
	TString OMEGAPI = gettreename(0); //
	TString KPM = gettreename(1); //
	TString KSL = gettreename(2); //
	TString THREEPIGAM = gettreename(3); //
	TString THREEPI = gettreename(4); //
	TString ETAGAM = gettreename(5); //
	TString BKGSUM1 = gettreename(6); //
	TString BKGSUM2 = gettreename(7); //
	TString MCSUM = gettreename(8);
	TString EEG = gettreename(9); //std::cout<<EEG<<endl;
	TString DATA = gettreename(10); //std::cout<<DATA<<endl;
	// branche names
	TString Smctype = getbraname(0);
	TString SIMthreepi = getbraname(1); //std::cout<<getbraname(1)<<endl;
	TString SEisr = getbraname(2); //std::cout<<getbraname(2)<<endl;
	TString Schi2value = getbraname(3); 
	TString SBestPiTime = getbraname(5); //std::cout<<getbraname(5)<<endl;
	TString SBestETime = getbraname(6); //std::cout<<getbraname(6)<<endl;
	TString SDeltaE = getbraname(7); //std::cout<<getbraname(7)<<endl;
	TString STracksum = getbraname(8); //std::cout<<getbraname(8)<<endl;
	TString SThreepiIM = getbraname(9); //std::cout<<getbraname(9)<<endl; 
	TString SIMdiff = getbraname(10);
	TString SThreepiIM_impv = getbraname(11);
	TString SEmaxprompt = getbraname(12);
	TString SBestpiphoton1Ekinfit = getbraname(13);
	TString SBestpiphoton2Ekinfit = getbraname(14);
	TString SISRE = getbraname(15);
	TString SISRE_impv = getbraname(16);
	TString SPionphotonEsum = getbraname(17);
	TString SThreepiIM_nofit = getbraname(18);
	TString SIsrErec_nofit = getbraname(19);
	TString SIsrE_nofit = getbraname(20);
	TString SDiffisrE = getbraname(21);
	
	
	TTree *TOMEGAPI_MC = new TTree("T"+OMEGAPI+"_MC","recreate");
	TTree *TKPM_MC = new TTree("T"+KPM+"_MC","recreate");
	TTree *TKSL_MC = new TTree("T"+KSL+"_MC","recreate");
	TTree *TTHREEPI_MC = new TTree("T"+THREEPI+"_MC","recreate");	
	TTree *TTHREEPIGAM_MC = new TTree("T"+THREEPIGAM+"_MC","recreate");
	TTree *TETAGAM_MC = new TTree("T"+ETAGAM+"_MC","recreate");
	TTree *TBKGSUM1_MC = new TTree("T"+BKGSUM1+"_MC","recreate");
	TTree *TBKGSUM2_MC = new TTree("T"+BKGSUM2+"_MC","recreate");
	TTree *TMCSUM_MC = new TTree("T"+MCSUM+"_MC","recreate");
	TTree *TEEG_MC = new TTree("T"+EEG+"_MC","recreate");
	TTree *TDATA = new TTree("T"+DATA,"recreate");

	TTree *TOMEGAPI_Pre = new TTree("T"+OMEGAPI+"_Pre","recreate");
	TTree *TKPM_Pre = new TTree("T"+KPM+"_Pre","recreate");
	TTree *TKSL_Pre = new TTree("T"+KSL+"_Pre","recreate");
	TTree *TTHREEPI_Pre = new TTree("T"+THREEPI+"_Pre","recreate");
	TTree *TTHREEPIGAM_Pre = new TTree("T"+THREEPIGAM+"_Pre","recreate");	
	TTree *TETAGAM_Pre = new TTree("T"+ETAGAM+"_Pre","recreate"); 	
	TTree *TBKGSUM1_Pre = new TTree("T"+BKGSUM1+"_Pre","recreate");
	TTree *TBKGSUM2_Pre = new TTree("T"+BKGSUM2+"_Pre","recreate");
	TTree *TMCSUM_Pre = new TTree("T"+MCSUM+"_Pre","recreate");
	TTree *TEEG_Pre = new TTree("T"+EEG+"_Pre","recreate");
	TTree *TDATA_Pre = new TTree("T"+DATA+"_Pre","recreate");
	
	// add trees into TList
	TCollection* treelist = new TList;
	treelist->Add(TOMEGAPI_MC); 
	treelist->Add(TKPM_MC);	
	treelist->Add(TKSL_MC);	
	treelist->Add(TTHREEPI_MC);
	treelist->Add(TTHREEPIGAM_MC);
	treelist->Add(TETAGAM_MC);
	treelist->Add(TBKGSUM1_MC);
	treelist->Add(TBKGSUM2_MC); 
	treelist->Add(TMCSUM_MC);
	treelist->Add(TEEG_MC);
	treelist->Add(TDATA);
		
	treelist->Add(TOMEGAPI_Pre);
	treelist->Add(TKPM_Pre);
	treelist->Add(TKSL_Pre);	
	treelist->Add(TTHREEPI_Pre);
	treelist->Add(TTHREEPIGAM_Pre);
	treelist->Add(TETAGAM_Pre); 
	treelist->Add(TBKGSUM1_Pre);
	treelist->Add(TBKGSUM2_Pre);
	treelist->Add(TMCSUM_Pre);
	treelist->Add(TEEG_Pre);
	treelist->Add(TDATA_Pre);
	
	// scan the list and add branches	
	TObject* treeout=0;
	TIter treeliter(treelist);
	while((treeout=treeliter.Next()) !=0) {
		//treeout->Print();
		TTree* tree_temp=dynamic_cast<TTree*>(treeout);
		tree_temp->Branch(SIMthreepi+"_MC",&threepiIM_MC,SIMthreepi+"_MC/D");
		tree_temp->Branch(SEisr+"_MC",&isrE_MC,SEisr+"/D");
		tree_temp->Branch(Schi2value,&chi2value,Schi2value+"/D");
		tree_temp->Branch(SBestPiTime,&bestPiTime,SBestPiTime+"/D");
		tree_temp->Branch(SBestETime,&bestETime,SBestETime+"/D");
		tree_temp->Branch(SDeltaE,&deltaE,SDeltaE+"/D");
		tree_temp->Branch(Smctype,&mctype,Smctype+"/I");
		tree_temp->Branch(STracksum,&tracksum,STracksum+"/D");
		tree_temp->Branch(SThreepiIM,&threepiIM,SThreepiIM+"/D");
		tree_temp->Branch(SThreepiIM_impv,&threepiIM_impv,SThreepiIM_impv+"/D");
		tree_temp->Branch(SIMdiff,&IMdiff,SIMdiff+"/D");
		tree_temp->Branch(SEmaxprompt,&Emaxprompt,SEmaxprompt+"/D");
		tree_temp->Branch(SBestpiphoton1Ekinfit,&bestpiphoton1Ekinfit,SBestpiphoton1Ekinfit+"/D");
		tree_temp->Branch(SBestpiphoton2Ekinfit,&bestpiphoton2Ekinfit,SBestpiphoton2Ekinfit+"/D");
		tree_temp->Branch(SISRE,&isrE,SISRE+"/D");
		tree_temp->Branch(SISRE_impv,&isrE_impv,SISRE_impv+"/D");
		tree_temp->Branch(SPionphotonEsum,&pionphotonEsum,SPionphotonEsum+"/D");
		tree_temp->Branch(SThreepiIM_nofit,&threepiIM_nofit,SThreepiIM_nofit+"/D");
		tree_temp->Branch(SIsrErec_nofit,&isrErec_nofit,SIsrErec_nofit+"/D");
		tree_temp->Branch(SIsrE_nofit,&isrE_nofit,SIsrE_nofit+"/D");
		tree_temp->Branch(SDiffisrE,&diffisrE,SDiffisrE+"/D");
	}
	
	// define chain
	TChain *allchainrho_mc = new TChain("ALLCHAIN_MC");
	TChain *allchainksl_mc = new TChain("ALLCHAIN_MC");
	TChain *allchaineeg_mc = new TChain("ALLCHAIN_MC");
	TChain *allchaindata = new TChain("ALLCHAIN_MC");
	
	TChain *allchainrho_pre = new TChain("ALLCHAIN_Pre");
	TChain *allchainksl_pre = new TChain("ALLCHAIN_Pre");
	TChain *allchaineeg_pre = new TChain("ALLCHAIN_Pre");
	TChain *allchaindata_pre = new TChain("ALLCHAIN_Pre");

	// create chain list
	TCollection* chainlist = new TList; 
	chainlist->Add(allchainrho_mc);
	chainlist->Add(allchainksl_mc);
	chainlist->Add(allchaineeg_mc);
	chainlist->Add(allchaindata);
	
	chainlist->Add(allchainrho_pre);
	chainlist->Add(allchainksl_pre);
	chainlist->Add(allchaineeg_pre); 
	chainlist->Add(allchaindata_pre);

	// mcrho samples, threepi-isr hadronic events
	string line;
   ifstream filelist("./mcrhoutpath");
   //  ifstream filelist("filelist.txt");
   if (filelist.is_open()) {
      while (!filelist.eof()) {
         if (getline(filelist, line, '\n')){
            if (line[0] != '!') {          	
               allchainrho_mc->Add(line.data()); 
               allchainrho_pre->Add(line.data());                            
               //cout << "Adding file: " << line << " to the chain of files" << endl;       
               // scan the list and add branches	
					TObject* chainout=0;
					TIter chainliter(chainlist);
					while((chainout=chainliter.Next()) !=0) {
						//chainout->Print();
						TTree* chain_temp=dynamic_cast<TTree*>(chainout);
						chain_temp->SetBranchAddress(SIMthreepi+"_MC",&threepiIM_MC);
						chain_temp->SetBranchAddress(SEisr+"_MC",&isrE_MC);
						chain_temp->SetBranchAddress(Smctype,&mctype);
						chain_temp->SetBranchAddress(Schi2value,&chi2value);
						chain_temp->SetBranchAddress(SBestPiTime,&bestPiTime);
						chain_temp->SetBranchAddress(SBestETime,&bestETime);
						chain_temp->SetBranchAddress(SDeltaE,&deltaE);
						chain_temp->SetBranchAddress(STracksum,&tracksum);
						chain_temp->SetBranchAddress(SThreepiIM,&threepiIM);
						chain_temp->SetBranchAddress(SThreepiIM_impv,&threepiIM_impv);
						chain_temp->SetBranchAddress(SIMdiff,&IMdiff);
						chain_temp->SetBranchAddress(SEmaxprompt,&Emaxprompt);
						chain_temp->SetBranchAddress(SISRE,&isrE);
						chain_temp->SetBranchAddress(SISRE_impv,&isrE_impv);
						chain_temp->SetBranchAddress(SPionphotonEsum,&pionphotonEsum);
						chain_temp->SetBranchAddress(SThreepiIM_nofit,&threepiIM_nofit);
						chain_temp->SetBranchAddress(SIsrErec_nofit,&isrErec_nofit);
						chain_temp->SetBranchAddress(SIsrE_nofit,&isrE_nofit);
						chain_temp->SetBranchAddress(SDiffisrE,&diffisrE);
					}	
               
            }
         }
      }
      filelist.close();
   } else {
      cout << "Unable to open filelist" << endl;
      return 0;
   }
   //
   string line;
   ifstream filelist1("./mcksloutpath");
   if (filelist1.is_open()) {
      while (!filelist1.eof()) {
         if (getline(filelist1, line, '\n')){
            if (line[0] != '!') {          	
               allchainksl_mc->Add(line.data());          
               allchainksl_pre->Add(line.data());                  
               //cout << "Adding file: " << line << " to the chain of files" << endl;       
               // scan the list and add branches	
					TObject* chainout=0;
					TIter chainliter(chainlist);
					while((chainout=chainliter.Next()) !=0) {
						//chainout->Print();
						TTree* chain_temp=dynamic_cast<TTree*>(chainout);
						chain_temp->SetBranchAddress(SIMthreepi+"_MC",&threepiIM_MC);
						chain_temp->SetBranchAddress(SEisr+"_MC",&isrE_MC);
						chain_temp->SetBranchAddress(Smctype,&mctype);
						chain_temp->SetBranchAddress(Schi2value,&chi2value);
						chain_temp->SetBranchAddress(SBestPiTime,&bestPiTime);
						chain_temp->SetBranchAddress(SBestETime,&bestETime);
						chain_temp->SetBranchAddress(SDeltaE,&deltaE);
						chain_temp->SetBranchAddress(STracksum,&tracksum);
						chain_temp->SetBranchAddress(SThreepiIM,&threepiIM);
						chain_temp->SetBranchAddress(SThreepiIM_impv,&threepiIM_impv);
						chain_temp->SetBranchAddress(SIMdiff,&IMdiff);
						chain_temp->SetBranchAddress(SEmaxprompt,&Emaxprompt);
						chain_temp->SetBranchAddress(SISRE,&isrE);
						chain_temp->SetBranchAddress(SISRE_impv,&isrE_impv);
						chain_temp->SetBranchAddress(SPionphotonEsum,&pionphotonEsum);
						chain_temp->SetBranchAddress(SThreepiIM_nofit,&threepiIM_nofit);
						chain_temp->SetBranchAddress(SIsrErec_nofit,&isrErec_nofit);
						chain_temp->SetBranchAddress(SIsrE_nofit,&isrE_nofit);
						chain_temp->SetBranchAddress(SDiffisrE,&diffisrE);
					}	
            }
         }
      }
      filelist1.close();
   } else {
      cout << "Unable to open filelist1" << endl;
      return 0;
   }
   //
   string line;
   ifstream filelist2("./mceegoutpath");
   if (filelist2.is_open()) {
      while (!filelist2.eof()) {
         if (getline(filelist2, line, '\n')){
            if (line[0] != '!') {          	
               allchaineeg_mc->Add(line.data());          
               allchaineeg_pre->Add(line.data());                  
               //cout << "Adding file: " << line << " to the chain of files" << endl;       
               // scan the list and add branches	
					TObject* chainout=0;
					TIter chainliter(chainlist);
					while((chainout=chainliter.Next()) !=0) {
						//chainout->Print();
						TTree* chain_temp=dynamic_cast<TTree*>(chainout);
						chain_temp->SetBranchAddress(SIMthreepi+"_MC",&threepiIM_MC);
						chain_temp->SetBranchAddress(SEisr+"_MC",&isrE_MC);
						chain_temp->SetBranchAddress(Smctype,&mctype);
						chain_temp->SetBranchAddress(Schi2value,&chi2value);
						chain_temp->SetBranchAddress(SBestPiTime,&bestPiTime);
						chain_temp->SetBranchAddress(SBestETime,&bestETime);
						chain_temp->SetBranchAddress(SDeltaE,&deltaE);
						chain_temp->SetBranchAddress(STracksum,&tracksum);
						chain_temp->SetBranchAddress(SThreepiIM,&threepiIM);
						chain_temp->SetBranchAddress(SThreepiIM_impv,&threepiIM_impv);
						chain_temp->SetBranchAddress(SIMdiff,&IMdiff);
						chain_temp->SetBranchAddress(SEmaxprompt,&Emaxprompt);
						chain_temp->SetBranchAddress(SISRE,&isrE);
						chain_temp->SetBranchAddress(SISRE_impv,&isrE_impv);
						chain_temp->SetBranchAddress(SPionphotonEsum,&pionphotonEsum);
						chain_temp->SetBranchAddress(SThreepiIM_nofit,&threepiIM_nofit);
						chain_temp->SetBranchAddress(SIsrErec_nofit,&isrErec_nofit);
						chain_temp->SetBranchAddress(SIsrE_nofit,&isrE_nofit);
						chain_temp->SetBranchAddress(SDiffisrE,&diffisrE);
					}	
            }
         }
      }
      filelist2.close();
   } else {
      cout << "Unable to open filelist2" << endl;
      return 0;
   }
   
   string line;
   ifstream filelist3("./dataoutpath");
   if (filelist3.is_open()) {
      while (!filelist3.eof()) {
         if (getline(filelist3, line, '\n')){
            if (line[0] != '!') {          	
               allchaindata->Add(line.data());          
               allchaindata_pre->Add(line.data());                  
               //cout << "Adding file: " << line << " to the chain of files" << endl;       
               // scan the list and add branches	
					TObject* chainout=0;
					TIter chainliter(chainlist);
					while((chainout=chainliter.Next()) !=0) {
						//chainout->Print();
						TTree* chain_temp=dynamic_cast<TTree*>(chainout);
						chain_temp->SetBranchAddress(SIMthreepi+"_MC",&threepiIM_MC);
						chain_temp->SetBranchAddress(SEisr+"_MC",&isrE_MC);
						chain_temp->SetBranchAddress(Smctype,&mctype);
						chain_temp->SetBranchAddress(Schi2value,&chi2value);
						chain_temp->SetBranchAddress(SBestPiTime,&bestPiTime);
						chain_temp->SetBranchAddress(SBestETime,&bestETime);
						chain_temp->SetBranchAddress(SDeltaE,&deltaE);
						chain_temp->SetBranchAddress(STracksum,&tracksum);
						chain_temp->SetBranchAddress(SThreepiIM,&threepiIM);
						chain_temp->SetBranchAddress(SThreepiIM_impv,&threepiIM_impv);
						chain_temp->SetBranchAddress(SIMdiff,&IMdiff);
						chain_temp->SetBranchAddress(SEmaxprompt,&Emaxprompt);
						chain_temp->SetBranchAddress(SISRE,&isrE);
						chain_temp->SetBranchAddress(SISRE_impv,&isrE_impv);
						chain_temp->SetBranchAddress(SPionphotonEsum,&pionphotonEsum);
						chain_temp->SetBranchAddress(SThreepiIM_nofit,&threepiIM_nofit);
						chain_temp->SetBranchAddress(SIsrErec_nofit,&isrErec_nofit);
						chain_temp->SetBranchAddress(SIsrE_nofit,&isrE_nofit);
						chain_temp->SetBranchAddress(SDiffisrE,&diffisrE);
					}	
            }
         }
      }
      filelist3.close();
   } else {
      cout << "Unable to open filelist3" << endl;
      return 0;
   }

	/// fill trees
	/// generated MC events and data ///
	// signal
   Int_t mcsumNb_MC=0;
   Int_t omegamNb_MC=0;
   for (Int_t irow=0;irow<allchainrho_mc->GetEntries();irow++) {
   	allchainrho_mc->GetEntry(irow); 
   	if (mctype == 4) { /// threepi gamma
   		omegamNb_MC++; mcsumNb_MC++;
   		TTHREEPIGAM_MC->Fill();
   		TMCSUM_MC->Fill();
   	}	

   }
   
   // eeg
   Int_t eegNb_MC=0;
   for (Int_t irow=0;irow<allchaineeg_mc->GetEntries();irow++) {
   	allchaineeg_mc->GetEntry(irow); 
   	for (Int_t i=0;i<scale;i++) {
   		//cout<<scale<<endl;
   		eegNb_MC++; mcsumNb_MC++;
   		TEEG_MC->Fill();
   		TMCSUM_MC->Fill();
   	}	
   }
   
   // data
   Int_t dataNb=0;
   for (Int_t irow=0;irow<allchaindata->GetEntries();irow++) {
   	allchaindata->GetEntry(irow); 
   	dataNb++; 
   	TDATA->Fill();	
   }
   
   // all physics
   Int_t counter1=0;
   Int_t omegapiNb_MC=0, kpmNb_MC=0, kslNb_MC=0, threepiNb_MC=0, etagamNb_MC=0, bkgsum1Nb_MC=0, bkgsum2Nb_MC=0;
   for (Int_t irow=0;irow<allchainksl_mc->GetEntries();irow++) {
   	allchainksl_mc->GetEntry(irow); 
   	if (mctype == 1) {/// omega pi
   		omegapiNb_MC++; mcsumNb_MC++;
   		TOMEGAPI_MC->Fill();
   		TMCSUM_MC->Fill();
   	}	
   	else if (mctype == 2) {// kpm
   		kpmNb_MC++; mcsumNb_MC++;
   		TKPM_MC->Fill();
   		TMCSUM_MC->Fill();
   	}
   	else if (mctype == 3) {/// ksl
   		kslNb_MC++; mcsumNb_MC++;
   		TKSL_MC->Fill();
   		TMCSUM_MC->Fill();
   	}
   	else if (mctype == 5) {// threepi
   		threepiNb_MC++; mcsumNb_MC++;
   		TTHREEPI_MC->Fill();
   		TMCSUM_MC->Fill();
   	}
		else if (mctype == 7) {// eta gamma
			etagamNb_MC++; mcsumNb_MC++; counter1++; //cout<<counter1<<endl;
			TETAGAM_MC->Fill();
			TMCSUM_MC->Fill();
		}
		
		if (mctype==6 || mctype==8 || mctype==9) {// bkgsum1
			bkgsum1Nb_MC++; mcsumNb_MC++;
			TBKGSUM1_MC->Fill();
			TMCSUM_MC->Fill();
		}
		
		if (mctype==2 || mctype==5 || mctype==6 || mctype==7 || mctype==8 || mctype==9) {
			bkgsum2Nb_MC++;
			TBKGSUM2_MC->Fill();
		}
   }

   
   
   
   /// pre-selected MC events and data (with all cuts) ///
   // signal
   
   Double_t mcsumNb_Pre=0;
   Double_t omegamNb_Pre=0;
   for (Int_t irow=0;irow<allchainrho_pre->GetEntries();irow++) {
   	allchainrho_pre->GetEntry(irow); //cout<<irow<<endl;
   	//cout<<CUTTAG<<endl;
   	// CUT TYPE
		CUTYPE=getcutype(chi2value,bestETime,bestPiTime,deltaE,Emaxprompt,list); //cout<<CUTYPE<<endl;
   	//
   	if (!CUTYPE && CUTTAG) continue;
   	//cout<<CUTTAG[0]<<endl;
   	if (mctype == 4) {
   		omegamNb_Pre++; mcsumNb_Pre++;
   		TTHREEPIGAM_Pre->Fill();
   		TMCSUM_Pre->Fill();
   	}	

   }
   
   // eeg
   Int_t eegNb_Pre=0;
   for (Int_t irow=0;irow<allchaineeg_pre->GetEntries();irow++) {
   	allchaineeg_pre->GetEntry(irow); 
   	// CUT TYPE
   	CUTYPE=getcutype(chi2value,bestETime,bestPiTime,deltaE,Emaxprompt,list); 
   	if (!CUTYPE && CUTTAG) continue;
   	//cout<<cutype[0]<<endl;
   	for (Int_t i=0;i<scale;i++) {
   		eegNb_Pre++; mcsumNb_Pre++;
   		TEEG_Pre->Fill();
   		TMCSUM_Pre->Fill();
   	}
   }
   
   // data
   Double_t dataNb_Pre=0;
   for (Int_t irow=0;irow<allchaindata_pre->GetEntries();irow++) {
   	allchaindata_pre->GetEntry(irow);
   	// CUT TYPE
   	CUTYPE=getcutype(chi2value,bestETime,bestPiTime,deltaE,Emaxprompt,list); 
   	if (!CUTYPE && CUTTAG) continue;
   	dataNb_Pre++; 
   	TDATA_Pre->Fill();	
   }
   
   // allphysics
   Int_t counter2=0;
   Int_t omegapiNb_Pre=0, kpmNb_Pre=0, kslNb_Pre=0, threepiNb_Pre=0, etagamNb_Pre=0, bkgsum1Nb_Pre=0, bkgsum2Nb_Pre=0;
   for (Int_t irow=0;irow<allchainksl_pre->GetEntries();irow++) {
   	allchainksl_pre->GetEntry(irow); 
   	// CUT TYPE
   	CUTYPE=getcutype(chi2value,bestETime,bestPiTime,deltaE,Emaxprompt,list); 
   	if (!CUTYPE && CUTTAG) continue; 	
   	//cout<<CUTTAG[0]<<endl;	
   	if (mctype == 1) {/// omega pi
   		omegapiNb_Pre++; mcsumNb_Pre++;
   		TOMEGAPI_Pre->Fill();
   		TMCSUM_Pre->Fill();
   	}
   	else if (mctype == 2) {// kpm
   		kpmNb_Pre++; mcsumNb_Pre++;
   		TKPM_Pre->Fill();
   		TMCSUM_Pre->Fill();
   	}
   	else if (mctype == 3) {/// ksl
   		kslNb_Pre++; mcsumNb_Pre++;
   		TKSL_Pre->Fill();
   		TMCSUM_Pre->Fill();
   	}
   	else if (mctype == 5) {// threepi
   		threepiNb_Pre++; mcsumNb_Pre++;
   		TTHREEPI_Pre->Fill();
   		TMCSUM_Pre->Fill();
   	}
   	else if (mctype == 7) {/// eta gamma
   		etagamNb_Pre++; mcsumNb_Pre++; 
			TETAGAM_Pre->Fill();
			TMCSUM_Pre->Fill();
   	}
   	
   	if (mctype==6 || mctype==8 || mctype==9) {// bkgsum1
			bkgsum1Nb_Pre++; mcsumNb_Pre++;
			TBKGSUM1_Pre->Fill();
			TMCSUM_Pre->Fill();
		}
		
		if (mctype==2 || mctype==5 || mctype==6 || mctype==7 || mctype==8 || mctype==9) {// bkgsum2
			bkgsum2Nb_Pre++;
			TBKGSUM2_Pre->Fill();
		}
   }
   
   
   Double_t SBLIST [3] = {0.,0.,0.};
   Double_t sb_Pre = omegamNb_Pre/(mcsumNb_Pre-omegamNb_Pre);
   SBLIST[0] = (omegamNb_Pre/mcsumNb_Pre)*dataNb_Pre;
   //count<<mcsumNb_Pre<<endl;
   //cout<<dataNb<<endl;
   //cout<<TMath::Sqrt(mcsumNb_Pre)<<endl;
	std::cout<<"# score function = "<<SBLIST[0]<<", "+cutname[index]+"= "<<list[index]<<endl;
	//cout<<list[index]-Cutlist_std[index]<<endl;
   //cout<<Cutlist_std[index]<<endl;
   if (list[index]==Cutlist_std[index]) {
   	printf("\nSTANDARD CUTS ARE SPOTTED \n", index);
		printf("=================Generated=================\n");
   	printf("1. # OMEGAPI_MC = %d \n", omegapiNb_MC);
   	printf("2. # KPM_MC = %d \n", kpmNb_MC);
   	printf("3. # KSL_MC = %d \n", kslNb_MC);
   	printf("4. # ThreePiGam_MC = %d \n", omegamNb_MC);  
   	printf("5. # ThreePi_MC = %d \n", threepiNb_MC); 
   	printf("6. # ETAGam_MC = %d \n", etagamNb_MC);
   	printf("7. # BKGSUM1_MC = %d \n", bkgsum1Nb_MC);
   	printf("8. # BKGSUM2_MC = %d \n", bkgsum2Nb_MC);
   	printf("9. # EEG_MC = %d \n", eegNb_MC);
   	printf("============================================\n");
   	printf("# MCSUM_MC = %d, DATA = %d \n", mcsumNb_MC, dataNb);
   	// check cut
   	if (CUTTAG == 0) {
   		printf("================Pre-Selected============\n");
   	
   	}
   	else {
   		printf("==================Cutted==================\n");	
   	}
   
   	printf("1. # OMEGAPI_Pre = %d \n", omegapiNb_Pre);
   	printf("2. # KPM_Pre = %d \n", kpmNb_Pre);
   	printf("3. # KSL_Pre = %d \n", kslNb_Pre);
   	printf("4. # ThreePiGam_Pre = %g \n", omegamNb_Pre);  
   	printf("5. # ThreePi_Pre = %d \n", threepiNb_Pre); 
   	printf("6. # ETAGam_Pre = %d \n", etagamNb_Pre);
   	printf("7. # BKGSUM1_Pre = %d \n", bkgsum1Nb_Pre);
   	printf("8. # BKGSUM2_Pre = %d \n", bkgsum2Nb_Pre);
   	printf("9. # EEG_Pre = %d \n", eegNb_Pre);
   	printf("============================================\n");
   	printf("# MCSUM_Pre = %g, Data = %d \n", mcsumNb_Pre, dataNb_Pre);
   	printf("# S/B_Pre = %g \n", sb_Pre);
   	printf("~~~~~~~~~~~~~~~~~~~~~END~~~~~~~~~~~~~~~~~~~~\n\n");
   
   	TFile ftree("./ROOT/TREE_Gen.root","recreate");
		TTHREEPIGAM_MC->Write();
		TOMEGAPI_MC->Write();
		TKSL_MC->Write();
		TTHREEPI_MC->Write();
		TETAGAM_MC->Write();
		TBKGSUM1_MC->Write();
		TBKGSUM2_MC->Write();
		TMCSUM_MC->Write();
		TEEG_MC->Write();
		TDATA->Write();	
		
		if (!CUTTAG){
			TFile ftree("./ROOT/TREE_Pre.root","recreate");
		}
		else {
			TFile ftree("./ROOT/TREE_"+cutname[index]+".root","recreate");
		}	
		TOMEGAPI_Pre->Write();
		TTHREEPIGAM_Pre->Write();
		TKPM_Pre->Write();
		TKSL_Pre->Write();
		TTHREEPI_Pre->Write();
		TETAGAM_Pre->Write();
		TBKGSUM1_Pre->Write();
		TBKGSUM2_Pre->Write();
		TMCSUM_Pre->Write();
		TEEG_Pre->Write();
		TDATA_Pre->Write();
	}	
	
	return SBLIST[];

}

void getree () {
	gStyle->SetOptTitle(0);
   gStyle->SetStatBorderSize(0);
   gStyle->SetOptStat(0);
   gStyle->SetLineScalePS(2);
   TGaxis::SetMaxDigits(3);
	
	double lb = Cutlist_std[modpos]-step*nbstep, upb = Cutlist_std[modpos]+step*nbstep;
	const int STEP=nbstep*2+1;
	//cout<<modpos<<endl;
	// check modification list stores all cadidate values for cuts	
	if (CUTTAG){
		std::cout<<"Cut: "<<cutname[modpos]<<" varies within ["<<lb<<","<<upb<<"] with a step "<<step<<endl;
		std::cout<<"Total "<<STEP-1<<" modifications with respect to "<<Cutlist_std[modpos]<<endl;
	}
	// create cut target list for modification and sepcify which cut value one wants to modified	
	Double_t modlist[STEP]; // length of modification list needs to be same as STEP
	Double_t sblist[STEP];
	Double_t Cutlist[NbCut]; // create cutlist will store specific modified cut value
	for (int i=0;i<NbCut;i++) {// initialize cutlist by copy cutlist_sta to it
		Cutlist[i]=Cutlist_std[i];
		//cout<<Cutlist[i]<<endl;
	}
	Int_t index_mod=0;
	for (int i=0;i<STEP;i++) {// initialize modification list
		modlist[i]=0.;
		sblist[i]=0.;
	}
	//Double_t value_temp=index_mod*step;
	//cout<<upb-step<<endl;
	Double_t sb_temp = 0.;
	for (int i=0;i<STEP;i++) {
		cout<<"\nMOD "<<i+1<<" // ";
		modlist[i] = lb; 
		//cout<<lb<<endl;
		/*for (int k=0;k<NbCut;k++) {// initialize cutlist by copy cutlist_sta to it
			if (k==modpos) {
				Cutlist[k]=lb;
				//std::cout<<cutname[modpos]<<" is modified from "<<Cutlist_std[modpos]<<" to "<<Cutlist[k]<<endl;
				//cout<<Cutlist[i]<<endl;
			}
			else {
				Cutlist[k]=Cutlist_std[k];
			}
			
		}*/
		Cutlist[modpos]=Cutlist_std[modpos]-step*(nbstep-i);
		//cout<<Cutlist[modpos]-Cutlist_std[modpos]<<endl;
		sb_temp=tree(Cutlist,modpos)[0]; 
		sblist[i]=sb_temp;
		lb+=step; 
	}
	std::cout<<"\n---------"<<endl;
	/*while (lb<upb+step) {
		cout<<index_mod<<endl;
		//cout<<upb<<endl;
		//value_temp=lb+index_mod*step; cout<<index_mod*step<<endl;
		modlist[index_mod] = lb; //cout<<modlist[index_mod]<<endl;
		// fill cutlist for each modified value at specific postion
		for (int i=0;i<NbCut;i++) {// initialize cutlist by copy cutlist_sta to it
			if (i==modpos) {
				Cutlist[i]=lb;
				//std::cout<<cutname[modpos]<<" is modified from "<<Cutlist_std[modpos]<<" to "<<Cutlist[i]<<endl;
				//cout<<Cutlist[i]<<endl;
			}
			else {
				Cutlist[i]=Cutlist_std[i];
			}
			//cout<<Cutlist[i]<<endl;
		}
		//sb_temp=tree(Cutlist,modpos); 
		//sblist[index_mod]=sb_temp;
		//cout<<"sb = "<<sblist[index_mod]<<", chi2cut = "<<modlist[index_mod]<<endl;
		lb+=step;
		index_mod++;		
		
	}*/
	Int_t index=0;
	for (Int_t i=0;i<NbCut;i++) {
		if (Cutlist_std[i]!=Cutlist[i]) {
			index++;
			
		}
		else {
			index=0;
		}
	}
	if (index>=2) {
		std::cout<<"More than one cut values have been modified at the same time!. Modify ONE cut value at a time!!!"<<endl;
	}
	else {
		std::cout<<"One cut value has been modified"<<endl;
	}
	//cout<<Cutlist[0]<<endl;
	
	TCanvas *c = new TCanvas("c","optimization of chi2 cut",700,700);
	c->cd(1);
	TGraph* gf= new TGraph(STEP,modlist,sblist);
	gf->GetYaxis()->SetTitleOffset(1.2);
	gf->GetXaxis()->SetTitle(xname[modpos]);
	gf->GetYaxis()->SetTitle("Number of e^{+}e^{-}#rightarrow#pi^{+}#pi^{-}#pi^{0}#gamma events");	
	gf->SetLineWidth(3); 
	gf->SetMarkerStyle(21);
	//gf->SetLineColor(2);
	gf->Draw("AP");
	//gf->Draw("CP");
	//gf->Draw("P");
	//gf->GetXaxis()->SetNdivisions(505);
	//gf->GetYaxis()->SetNdivisions(505);
	
	if (CUTTAG){
		TFile hf("./Plots/optimcuts_"+cutname[modpos]+".root","recreate");
   	c->Write();
   }
	
}
