#include "Getname.C"

#include <iostream>
#include <string>

using namespace std;

int Gettree() 
{
	TFile ftree("./tree.root","recreate");
	Double_t IMthreepi = 0.;
	// tree names
	TString OMEGAPI = gettreename(0); 
	TString KPM = gettreename(1); //std::cout<<gettreename(1)<<endl
	TString KSL = gettreename(2);
	TString THREEPIGAM = gettreename(3);
	TString THREEPI = gettreename(4);
	TString ETAGAM = gettreename(5);
	TString BKGSUM1 = gettreename(6);
	TString BKGSUM2 = gettreename(7);
	// branche names
	TString Smctype = getbraname(0);
	TString SIMthreepi = getbraname(1); //std::cout<<getbraname(1)<<endl;
	TString SEisr = getbraname(2); //std::cout<<getbraname(2)<<endl;
	
	TTree *TTHREEPIGAM_MC = new TTree("T"+THREEPIGAM+"_MC","recreate");
	TTree *TETAGAM_MC = new TTree("T"+ETAGAM+"_MC","recreate");
	// add trees into TList
	TCollection* treelist = new TList; 
	treelist->Add(TTHREEPIGAM_MC);
	treelist->Add(TETAGAM_MC);
	// scan the list and add branches	
	TObject* treeout=0;
	TIter treeliter(treelist);
	while((treeout=treeliter.Next()) !=0) {
		//treeout->Print();
		TTree* tree_temp=dynamic_cast<TTree*>(treeout);
		tree_temp->Branch(SIMthreepi+"_MC",&IMthreepi,SIMthreepi+"/D");
	}	
	// define chains
	TChain *omegam_mc = new TChain(THREEPIGAM+"_MC");
	TChain *etagam_mc = new TChain(ETAGAM+"_MC");
	// create chain list
	TCollection* chainlist = new TList; 
	chainlist->Add(omegam_mc);
	//
	string line;
   ifstream filelist("./mcksloutpath");
   //  ifstream filelist("filelist.txt");
   if (filelist.is_open()) {
      while (!filelist.eof()) {
         if (getline(filelist, line, '\n')){
            if (line[0] != '!') {            	
               omegam_mc->Add(line.data());
               etagam_mc->Add(line.data());
               cout << "Adding file: " << line << " to the chain of files" << endl;   
               // add trees into TList						          
            
               // scan the list and add branches	
					TObject* chainout=0;
					TIter chainliter(chainlist);
					while((chainout=chainliter.Next()) !=0) {
						//chainout->Print();
						TTree* chain_temp=dynamic_cast<TTree*>(chainout);
						omegam_mc->SetBranchAddress(SIMthreepi,&IMthreepi);
					}	
               
            }
         }
      }
      filelist.close();
   } else {
      cout << "Unable to open filelist" << endl;
      return 0;
   }
   
   Int_t omegamNb_MC=0;
   for (Int_t irow=0;irow<omegam_mc->GetEntries();irow++) {
   	omegamNb_MC++; 
   	omegam_mc->GetEntry(irow); 
   	//cout<<IMthreepi<<endl;
   	TTHREEPIGAM_MC->Fill();
   } 
   
   printf("# ThreePiGam = %d \n", omegamNb_MC);
   TTHREEPIGAM_MC->Write();
   
   
   
   
   
   
   
   
   
   
   
}
