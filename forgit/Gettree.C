#include "Getname.C"
#include <iostream>
#include <string>

using namespace std;

void Gettree() 
{
	TFile ftree("./tree.root","recreate");
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
	TChain *omegapi_mc = new TChain(OMEGAPI+"_MC");
	TChain *kpm_mc = new TChain(KPM+"_MC");
	TChain *ksl_mc = new TChain(KSL+"_MC");
	TChain *threepigam_mc = new TChain(THREEPIGAM+"_MC");
	TChain *threepi_mc = new TChain(THREEPI+"_MC");
	TChain *etagam_mc = new TChain(ETAGAM+"_MC");
	TChain *bkgsum1_mc = new TChain(BKGSUM1+"_MC");
	TChain *bkgsum2_mc = new TChain(BKGSUM2+"_MC");

	// create chain list
	TCollection* chainlist = new TList; 
	chainlist->Add(omegapi_mc);
	chainlist->Add(kpm_mc);
	chainlist->Add(ksl_mc);
	chainlist->Add(threepigam_mc);
	chainlist->Add(threepi_mc);
	chainlist->Add(etagam_mc);		

	// mcrho samples, threepi-isr hadronic events
	string line;
   ifstream filelist("./mcrhoutpath");
   //  ifstream filelist("filelist.txt");
   if (filelist.is_open()) {
      while (!filelist.eof()) {
         if (getline(filelist, line, '\n')){
            if (line[0] != '!') {          	
               threepigam_mc->Add(line.data());                            
               cout << "Adding file: " << line << " to the chain of files" << endl;       
               // scan the list and add branches	
					TObject* chainout=0;
					TIter chainliter(chainlist);
					while((chainout=chainliter.Next()) !=0) {
						//chainout->Print();
						TTree* chain_temp=dynamic_cast<TTree*>(chainout);
						chain_temp->SetBranchAddress(SIMthreepi,&threepiIM);
						chain_temp->SetBranchAddress(SEisr,&isrE);
					}	
               
            }
         }
      }
      filelist.close();
   } else {
      cout << "Unable to open filelist" << endl;
      return 0;
   }
   // mcksl samples, all physics bkg
   string line;
   ifstream filelist("./mcksloutpath");
   //  ifstream filelist("filelist.txt");
   if (filelist.is_open()) {
      while (!filelist.eof()) {
         if (getline(filelist, line, '\n')){
            if (line[0] != '!') { 
            	omegapi_mc->Add(line.data());
            	threepi_mc->Add(line.data());         
            	ksl_mc->Add(line.data());  	
            	kpm_mc->Add(line.data());  
               etagam_mc->Add(line.data());   
               bkgsum1_mc->Add(line.data());  
               bkgsum2_mc->Add(line.data());           
               cout << "Adding file: " << line << " to the chain of files" << endl;       
               // scan the list and add branches	
					TObject* chainout=0;
					TIter chainliter(chainlist);
					while((chainout=chainliter.Next()) !=0) {
						//chainout->Print();
						TTree* chain_temp=dynamic_cast<TTree*>(chainout);
						chain_temp->SetBranchAddress(SIMthreepi,&threepiIM);
						chain_temp->SetBranchAddress(SEisr,&isrE);
					}	
               
            }
         }
      }
      filelist.close();
   } else {
      cout << "Unable to open filelist" << endl;
      return 0;
   }
   // mceeg samples, barhbar bkg
   
   // data samples
   
   
   // fill globle trees
   Int_t mcsumNb_MC=0;
   Int_t omegapiNb_MC=0;
   for (Int_t irow=0;irow<omegapi_mc->GetEntries();irow++) {
   	omegapiNb_MC++; mcsumNb_MC++;
   	omegapi_mc->GetEntry(irow); 
   	//cout<<threepiIM<<endl;
   	TOMEGAPI_MC->Fill();
   	TMCSUM_MC->Fill();
   } 
   
   Int_t kpmNb_MC=0;
   for (Int_t irow=0;irow<kpm_mc->GetEntries();irow++) {
   	kpmNb_MC++; mcsumNb_MC++; 
   	kpm_mc->GetEntry(irow); 
   	//cout<<isrE<<endl;
   	TKPM_MC->Fill();
   	TMCSUM_MC->Fill();
   }
   
   Int_t kslNb_MC=0;
   for (Int_t irow=0;irow<ksl_mc->GetEntries();irow++) {
   	kslNb_MC++; mcsumNb_MC++;
   	ksl_mc->GetEntry(irow); 
   	//cout<<isrE<<endl;
   	TKSL_MC->Fill();
   	TMCSUM_MC->Fill();
   }   
   
   Int_t omegamNb_MC=0;
   for (Int_t irow=0;irow<threepigam_mc->GetEntries();irow++) {
   	omegamNb_MC++; mcsumNb_MC++;
   	threepigam_mc->GetEntry(irow); 
   	//cout<<threepiIM<<endl;
   	TTHREEPIGAM_MC->Fill();
   	TMCSUM_MC->Fill();
   } 
   
   Int_t threepiNb_MC=0;
   for (Int_t irow=0;irow<threepi_mc->GetEntries();irow++) {
   	threepiNb_MC++; mcsumNb_MC++;
   	threepi_mc->GetEntry(irow); 
   	//cout<<threepiIM<<endl;
   	TTHREEPI_MC->Fill();
   	TMCSUM_MC->Fill();
   } 
   
   Int_t etagamNb_MC=0;
   for (Int_t irow=0;irow<etagam_mc->GetEntries();irow++) {
   	etagamNb_MC++; mcsumNb_MC++;
   	etagam_mc->GetEntry(irow); 
   	//cout<<threepiIM<<endl;
   	TETAGAM_MC->Fill();
   	TMCSUM_MC->Fill();
   } 
   
   Int_t bkgsum1Nb_MC=0;
   for (Int_t irow=0;irow<bkgsum1_mc->GetEntries();irow++) {
   	bkgsum1Nb_MC++; mcsumNb_MC++;
   	bkgsum1_mc->GetEntry(irow); 
   	//cout<<threepiIM<<endl;
   	TBKGSUM1_MC->Fill();
   	TMCSUM_MC->Fill();
   } 
   
   Int_t bkgsum2Nb_MC=0;
   for (Int_t irow=0;irow<bkgsum2_mc->GetEntries();irow++) {
   	bkgsum2Nb_MC++;
   	bkgsum2_mc->GetEntry(irow); 
   	//cout<<threepiIM<<endl;
   	TBKGSUM2_MC->Fill();
   } 

	printf("=================Generated=================\n");
   printf("# OMEGAPI_MC = %d \n", omegapiNb_MC);
   printf("# KPM_MC = %d \n", kpmNb_MC);
   printf("# KSL_MC = %d \n", kslNb_MC);
   printf("# ThreePiGam_MC = %d \n", omegamNb_MC);  
   printf("# ThreePi_MC = %d \n", threepiNb_MC); 
   printf("# ETAGam_MC = %d \n", etagamNb_MC);
   printf("# BKGSUM1_MC = %d \n", bkgsum1Nb_MC);
   printf("# BKGSUM2_MC = %d \n", bkgsum2Nb_MC);
   printf("============================================\n");
   printf("# MCSUM_MC = %d \n", mcsumNb_MC);
   
   TOMEGAPI_MC->Write();
   TTHREEPIGAM_MC->Write();
   TTHREEPI_MC->Write();
   TETAGAM_MC->Write();
   TKPM_MC->Write();
   TKSL_MC->Write();
   BKGSUM1_MC->Write();
   BKGSUM2_MC->Write();
   TMCSUM_MC->Write();
   
   
   
   
   
   
   
   
   
   
   
}
