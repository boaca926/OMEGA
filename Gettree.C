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
	TString OMEGAPI = gettreename(0); 
	TString KPM = gettreename(1); 
	TString KSL = gettreename(2); //
	TString THREEPIGAM = gettreename(3); //
	TString THREEPI = gettreename(4);
	TString ETAGAM = gettreename(5); //
	TString BKGSUM1 = gettreename(6);
	TString BKGSUM2 = gettreename(7);
	// branche names
	TString Smctype = getbraname(0);
	TString SIMthreepi = getbraname(1); //std::cout<<getbraname(1)<<endl;
	TString SEisr = getbraname(2); //std::cout<<getbraname(2)<<endl;
	
	TTree *TKSL_MC = new TTree("T"+KSL+"_MC","recreate");
	TTree *TTHREEPIGAM_MC = new TTree("T"+THREEPIGAM+"_MC","recreate");	
	TTree *TETAGAM_MC = new TTree("T"+ETAGAM+"_MC","recreate");
	
	// add trees into TList
	TCollection* treelist = new TList; 
	treelist->Add(TKSL_MC);	
	treelist->Add(TTHREEPIGAM_MC);
	treelist->Add(TETAGAM_MC);
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
	TChain *ksl_mc = new TChain(KSL+"_MC");
	TChain *threepigam_mc = new TChain(THREEPIGAM+"_MC");
	TChain *etagam_mc = new TChain(ETAGAM+"_MC");	
	// create chain list
	TCollection* chainlist = new TList; 
	chainlist->Add(ksl_mc);
	chainlist->Add(threepigam_mc);
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
            	ksl_mc->Add(line.data());  	
               etagam_mc->Add(line.data());              
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
   Int_t kslNb_MC=0;
   for (Int_t irow=0;irow<ksl_mc->GetEntries();irow++) {
   	kslNb_MC++; 
   	ksl_mc->GetEntry(irow); 
   	//cout<<isrE<<endl;
   	TKSL_MC->Fill();
   }
   
   Int_t omegamNb_MC=0;
   for (Int_t irow=0;irow<threepigam_mc->GetEntries();irow++) {
   	omegamNb_MC++; 
   	//threepigam_mc->GetEntry(irow); 
   	cout<<threepiIM<<endl;
   	TTHREEPIGAM_MC->Fill();
   } 
   
   Int_t etagamNb_MC=0;
   for (Int_t irow=0;irow<etagam_mc->GetEntries();irow++) {
   	etagamNb_MC++; 
   	etagam_mc->GetEntry(irow); 
   	//cout<<threepiIM<<endl;
   	TETAGAM_MC->Fill();
   } 
      
   
   printf("# KSL_MC = %d \n", kslNb_MC);
   printf("# ThreePiGam_MC = %d \n", omegamNb_MC);  
   printf("# ETAGam_MC = %d \n", etagamNb_MC);
   
   TTHREEPIGAM_MC->Write();
   TETAGAM_MC->Write();
   TKSL_MC->Write();
   
   
   
   
   
   
   
   
   
   
   
}
