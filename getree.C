#include "Getname.C"
#include <iostream>
#include <string>

using namespace std;

void getree() 
{
	TFile ftree("./TREE.root","recreate");
	Int_t mctype = 0;
	Double_t threepiIM = 0.;
	Double_t isrE = 0.;
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
	TString ALLCHAIN = gettreename(9); //
	// branche names
	TString Smctype = getbraname(0);
	TString SIMthreepi = getbraname(1); //std::cout<<getbraname(1)<<endl;
	TString SEisr = getbraname(2); //std::cout<<getbraname(2)<<endl;
	
	TTree *TOMEGAPI_MC = new TTree("T"+OMEGAPI+"_MC","recreate");
	TTree *TKPM_MC = new TTree("T"+KPM+"_MC","recreate");
	TTree *TKSL_MC = new TTree("T"+KSL+"_MC","recreate");
	TTree *TTHREEPI_MC = new TTree("T"+THREEPI+"_MC","recreate");	
	TTree *TTHREEPIGAM_MC = new TTree("T"+THREEPIGAM+"_MC","recreate");
	TTree *TETAGAM_MC = new TTree("T"+ETAGAM+"_MC","recreate");
	TTree *TBKGSUM1_MC = new TTree("T"+BKGSUM1+"_MC","recreate");
	TTree *TBKGSUM2_MC = new TTree("T"+BKGSUM2+"_MC","recreate");
	TTree *TMCSUM_MC = new TTree("T"+MCSUM+"_MC","recreate");
	
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
	// scan the list and add branches	
	TObject* treeout=0;
	TIter treeliter(treelist);
	while((treeout=treeliter.Next()) !=0) {
		//treeout->Print();
		TTree* tree_temp=dynamic_cast<TTree*>(treeout);
		tree_temp->Branch(SIMthreepi+"_MC",&threepiIM,SIMthreepi+"/D");
		tree_temp->Branch(SEisr+"_MC",&isrE,SEisr+"/D");
	}
	
	// define chain
	TChain *allchainrho_mc = new TChain(ALLCHAIN+"_MC");
	TChain *allchainksl_mc = new TChain(ALLCHAIN+"_MC");

	// create chain list
	TCollection* chainlist = new TList; 
	chainlist->Add(allchainrho_mc);
	chainlist->Add(allchainksl_mc);

	// mcrho samples, threepi-isr hadronic events
	string line;
   ifstream filelist("./mcrhoutpath");
   ifstream filelist1("./mcksloutpath");
   //  ifstream filelist("filelist.txt");
   if (filelist.is_open()) {
      while (!filelist.eof()) {
         if (getline(filelist, line, '\n')){
            if (line[0] != '!') {          	
               allchainrho_mc->Add(line.data());                            
               cout << "Adding file: " << line << " to the chain of files" << endl;       
               // scan the list and add branches	
					TObject* chainout=0;
					TIter chainliter(chainlist);
					while((chainout=chainliter.Next()) !=0) {
						//chainout->Print();
						TTree* chain_temp=dynamic_cast<TTree*>(chainout);
						chain_temp->SetBranchAddress(SIMthreepi,&threepiIM);
						chain_temp->SetBranchAddress(SEisr,&isrE);
						chain_temp->SetBranchAddress(Smctype,&mctype);
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
   if (filelist1.is_open()) {
      while (!filelist1.eof()) {
         if (getline(filelist1, line, '\n')){
            if (line[0] != '!') {          	
               allchainksl_mc->Add(line.data());                            
               cout << "Adding file: " << line << " to the chain of files" << endl;       
               // scan the list and add branches	
					TObject* chainout=0;
					TIter chainliter(chainlist);
					while((chainout=chainliter.Next()) !=0) {
						//chainout->Print();
						TTree* chain_temp=dynamic_cast<TTree*>(chainout);
						chain_temp->SetBranchAddress(SIMthreepi,&threepiIM);
						chain_temp->SetBranchAddress(SEisr,&isrE);
						chain_temp->SetBranchAddress(Smctype,&mctype);
					}	
               
            }
         }
      }
      filelist1.close();
   } else {
      cout << "Unable to open filelist1" << endl;
      return 0;
   }

	// fill globle trees
   Int_t mcsumNb_MC=0;
   Int_t omegamNb_MC=0;
   for (Int_t irow=0;irow<allchainrho_mc->GetEntries();irow++) {
   	allchainrho_mc->GetEntry(irow); 
   	if (mctype == 4) {
   		omegamNb_MC++;
   		TTHREEPIGAM_MC->Fill();
   	}	

   }
   //
   Int_t omegapiNb_MC=0, kpmNb_MC=0;
   for (Int_t irow=0;irow<allchainksl_mc->GetEntries();irow++) {
   	allchainksl_mc->GetEntry(irow); 
   	if (mctype == 1) {
   		omegapiNb_MC++;
   		TOMEGAPI_MC->Fill();
   	}	
   	else if (mctype == 2) {
   		kpmNb_MC++;
   		TKPM_MC->Fill();
   	}

   }

	printf("=================Generated=================\n");
   printf("# OMEGAPI_MC = %d \n", omegapiNb_MC);
   printf("# KPM_MC = %d \n", kpmNb_MC);
   //printf("# KSL_MC = %d \n", kslNb_MC);
   printf("# ThreePiGam_MC = %d \n", omegamNb_MC);  
   //printf("# ThreePi_MC = %d \n", threepiNb_MC); 
   //printf("# ETAGam_MC = %d \n", etagamNb_MC);
   //printf("# BKGSUM1_MC = %d \n", bkgsum1Nb_MC);
   //printf("# BKGSUM2_MC = %d \n", bkgsum2Nb_MC);
   printf("============================================\n");
   //printf("# MCSUM_MC = %d \n", mcsumNb_MC);
	TTHREEPIGAM_MC->Write();
	TOMEGAPI_MC->Write();






























}
