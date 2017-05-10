#include <TChain.h>
#include <TTree.h>
#include <TString.h>
#include <TTimeStamp.h>
#include <TEnv.h>
#include <TCanvas.h>

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "MyClass.h"


int Analys_new(TString list_of_files, TString naming) {


  // char *list_of_files = new char[strlen(argv[2]) + 1];
  // strcpy(list_of_files, argv[2]);
  Int_t RUNNR=0;
  TChain *tree = new TChain("ETAPPG/h1");
  TFile *listrun;
  listrun = new TFile("listrun","RECREATE");
  // reading list of ROOT files from the file list
  // files can be commented with '!'
  string line;
  ifstream filelist(list_of_files); // = delete
  //  ifstream filelist("filelist.txt");
  if (filelist.is_open()) {
    while (!filelist.eof()) {
      if (getline(filelist, line, '\n'))
        if (line[0] != '!') {
          tree->Add(line.data());
          cout << "Adding file: " << line << " to the chain of files" << endl;
          tree->SetBranchAddress("run_nr",&RUNNR); 
          /*for (Int_t irow=0;irow<tree->GetEntries();irow++) {
      	 	tree->GetEntry(irow);      			
      	 }*/
      	 //cout<<RUNNR<<endl;
        }
    }
    filelist.close();
  } else {
    cout << "Unable to open filelist" << endl;
    return 0;
  }
  
  

 //  //MC del, kommentera bort för att köra data
 //  //open histrogram file here

  TFile *myfile;
  myfile = new TFile(naming+".root","RECREATE");

  MyClass *analysis = new MyClass(tree);
  analysis->Main();

  //saving and closing histogram file
  myfile->Write();
  myfile->Close();

  delete analysis;

//MC del slut------------------------------------



//för att köra data, kommentera bort MC delen
/*
  TFile *myfile;
  myfile = new TFile(naming+".root","RECREATE");


  DataClass *dataanalysis = new DataClass(tree);
  dataanalysis->Main();
  //saving and closing histogram file
  myfile->Write();
  myfile->Close();


  delete dataanalysis;
*/
//Data del slut----------------------------------
  
   /*TFile *f = TFile::Open(naming+".root", "read");
   TCanvas *c1=new TCanvas("c1","c1",800,800);
   TH1F *Test0 = (TH1F*)(f->FindObjectAny("pi+pi-pi0 M Event: 0"));
   TH1F *Test1 = (TH1F*)(f->FindObjectAny("pi+pi-pi0 M Event: 1"));
   Test1->SetLineColor(kRed);
   Test0->Draw();
   Test1->Draw("same");*/

   return 0;
}
