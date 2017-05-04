#define MyClass_cxx
#include "MyClass.h"
#include "TMatrixD.h"
#include "TVectorD.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TDecompSVD.h"
#include <sstream>
#include "Getname.C"

void MyClass::Main()
{
	Int_t mctype = 0;
	Double_t IMthreepi = 0., Eisr = 0.;
	
	// define structure
	typedef struct {		
		Double_t threepiIM, isrE;
	
	} EVTCLASS;
	static EVTCLASS omegam_mc;
	// get names
	TString OMEGAPI = gettreename(0); 
	TString KPM = gettreename(1); //std::cout<<gettreename(1)<<endl
	TString KSL = gettreename(2);
	TString THREEPIGAM = gettreename(3);
	TString THREEPI = gettreename(4);
	TString ETAGAM = gettreename(5);
	TString BKGSUM1 = gettreename(6);
	TString BKGSUM2 = gettreename(7);

	// creat trees and add to TList
	// MC
	TTree OMEGAMPI_MC(OMEGAPI+"_MC","recreate"); 
	TTree KPM_MC(KPM+"_MC","recreate"); 
	TTree KSL_MC(KSL+"_MC","recreate");
	TTree THREEPIGAM_MC(THREEPIGAM+"_MC","recreate");
	TTree THREEPI_MC(THREEPI+"_MC","recreate");
	TTree ETAGAM_MC(ETAGAM+"_MC","recreate");
	TTree BKGSUM1_MC(BKGSUM1+"_MC","recreate");
	TTree BKGSUM2_MC(BKGSUM2+"_MC","recreate");
	
	TCollection* treelist = new TList; 
	treelist->Add(&OMEGAMPI_MC);
	treelist->Add(&KPM_MC);
	treelist->Add(&KSL_MC);
	treelist->Add(&THREEPIGAM_MC);
	treelist->Add(&THREEPI_MC);
	treelist->Add(&ETAGAM_MC); 
	treelist->Add(&BKGSUM1_MC);
	treelist->Add(&BKGSUM2_MC);
	// pre selected
	// define branches
	TString Smctype = getbraname(0);
	TString SIMthreepi = getbraname(1); std::cout<<getbraname(1)<<endl;
	TString SEisr = getbraname(2); std::cout<<getbraname(2)<<endl;
	
	
	
	TObject* treeout=0;
	TIter treeliter(treelist);
	while((treeout=treeliter.Next()) !=0) {
		//treeout->Print();
		TTree* tree_temp=dynamic_cast<TTree*>(treeout);
		tree_temp->Branch(Smctype,&mctype,Smctype+"/I");
		tree_temp->Branch(SIMthreepi,&IMthreepi,SIMthreepi+"/D");
		tree_temp->Branch(SEisr,&Eisr,SEisr+"/D");
		//cout<<1<<endl;
	}	

	///
	
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      Beam.SetPxPyPzE(bpx,bpy,bpz,bene); //Beam.Print();
      TVector3 Boost3vector = -Beam.BoostVector();
		//
		TVector3 vector;
      Double_t pi0nb=0, piplnb=0, piminb=0, isr1nb=0, isr2nb=0, pipho1=0, pipho2=0;
      Double_t pi0nb_eta=0, piplnb_eta=0, piminb_eta=0, isr1nb_eta=0, isr2nb_eta=0, pipho1_eta=0, pipho2_eta=0;
      TLorentzVector true3pi(0.,0.,0.,0.), true3pi_eta(0.,0.,0.,0.);
      TLorentzVector truepi0(0.,0.,0.,0.), truepipl(0.,0.,0.,0.), truepimi(0.,0.,0.,0.), trueisr(0.,0.,0.,0.), truepipho1(0.,0.,0.,0.), truepipho2(0.,0.,0.,0.);
      TLorentzVector truepi0_eta(0.,0.,0.,0.), truepipl_eta(0.,0.,0.,0.), truepimi_eta(0.,0.,0.,0.), trueisr_eta(0.,0.,0.,0.), truepipho1_eta(0.,0.,0.,0.), truepipho2_eta(0.,0.,0.,0.);
      if (phid == 0) { // omega pi
      	mctype = 1; 
      	IMthreepi = 0.;
      	Eisr = 0.;
      	OMEGAMPI_MC.Fill();
      }
      else if (phid == 1) {
      	mctype = 2;
      	IMthreepi = 0.;
      	Eisr = 0.;
      	KPM_MC.Fill();
      }
      else if (phid == 2) {
      	mctype = 3;
      	IMthreepi = 0.;
      	Eisr = 0.;
      	KSL_MC.Fill();
      }
      else if (phid==3) {
      	if (kineid==311 || kineid==301) {
      		for (Int_t i = 0; i < ntmc; i++) {
      			vector.SetXYZ(pxmc[i],pymc[i],pzmc[i]);
			      // threepigam
			      if (pidmc[i] == 7 && virmom[i] == 54) {
			         pi0nb++;
			         truepi0 = GetLorentzVector(vector, massneupion);
			      }
			      else if (pidmc[i] == 8 && virmom[i] == 54) {
			         piplnb++;
			         truepipl = GetLorentzVector(vector, masschpion);
			      }
			      else if (pidmc[i] == 9 && virmom[i] == 54) {
			         piminb++;
			         truepimi = GetLorentzVector(vector, masschpion);
			      }
			      else if (pidmc[i] == 1 && mother[indv[i]-1] == 50 && isr1nb == 0 && isr2nb == 0) {
			         isr1nb++;
			         trueisr = GetLorentzVector(vector, 0.);
			      }
			      else if (pidmc[i] == 1 && mother[indv[i]-1] == 50 && isr1nb == 1 && isr2nb == 0) {
			         isr2nb++; 
			      } 
			      else if (pidmc[i] == 1 && mother[indv[i]-1] == 7 && pipho1 == 0 && pipho2 == 0) {
			         pipho1++;
			         truepipho1 = GetLorentzVector(vector, 0.);
			      }  
			      else if (pidmc[i] == 1 && mother[indv[i]-1] == 7 && pipho1 == 1 && pipho2 == 0) {
			         pipho2++;
			         truepipho2 = GetLorentzVector(vector, 0.);
			      }			      
      		}
      		true3pi=truepipl+truepimi+truepi0;
			   if (pi0nb == 1 && piplnb == 1 && piminb == 1 && isr1nb == 1 ) {	 
			   	mctype = 4;
			      Eisr=trueisr.E();			      
			      IMthreepi=true3pi.M();	
			      //omegam_mc.threepiIM=true3pi.M();	
			      //omegam_mc.isrE=trueisr.E();		     
			      THREEPIGAM_MC.Fill();
      		}
      		else {
      			mctype = 5; // three pi
			      IMthreepi=true3pi.M(); 
			      Eisr=trueisr.E();
      			THREEPI_MC.Fill();
      		}
      	}
      	else {
      		mctype=6; 
      	}   
      }
      else if (phid==5) {
      	if (kineid==507 || kineid==508) {
      		for (Int_t i = 0; i < ntmc; i++) {  
			      vector.SetXYZ(pxmc[i],pymc[i],pzmc[i]);
			      // threepigam
			      if (pidmc[i] == 7 && virmom[i] == 17) {
			         truepi0_eta = GetLorentzVector(vector, massneupion);
			      }
			      else if (pidmc[i] == 8 && virmom[i] == 17) {
			         truepipl_eta = GetLorentzVector(vector, masschpion);
			      }
			      else if (pidmc[i] == 9 && virmom[i] == 17) {
			         truepimi_eta = GetLorentzVector(vector, masschpion);
			      }
			      else if (pidmc[i] == 1 && mother[indv[i]-1] == 50 && isr1nb_eta == 0 && isr2nb_eta == 0) {
			         trueisr_eta = GetLorentzVector(vector, 0.);
			      }
			      else if (pidmc[i] == 1 && mother[indv[i]-1] == 50 && isr1nb_eta == 1 && isr2nb_eta == 0) {
			      	
			      } 
			      else if (pidmc[i] == 1 && mother[indv[i]-1] == 7 && pipho1_eta == 0 && pipho2_eta == 0) {
			         truepipho1_eta = GetLorentzVector(vector, 0.);
			      }  
			      else if (pidmc[i] == 1 && mother[indv[i]-1] == 7 && pipho1_eta == 1 && pipho2_eta == 0) {
			         truepipho2_eta = GetLorentzVector(vector, 0.);  
			      }  
			   }
			   true3pi_eta=truepipl_eta+truepimi_eta+truepi0_eta;	
			   IMthreepi=true3pi_eta.M(); 
			   Eisr=trueisr_eta.E();		   
      		mctype=7;// eta gamma
      		//threepiIM_MC=true3pi_eta.M(); 
      		ETAGAM_MC.Fill();
      	}
      	else {
      		mctype=8; 
      	}
      }	
      else {
      	mctype=9; 
      }	
      
      if (mctype==1 || mctype==2 || mctype==3 || mctype==4 || mctype==5 || mctype==7) {
      
      }
      else {
      	mctype=10;
      	BKGSUM1_MC.Fill();
      }
      
      if (mctype==1 || mctype==3 || mctype==4 ) {
      
      }
      else {
      	mctype=11;
      	BKGSUM2_MC.Fill();
      }
      
      
      
      
   }
   printf("speed of light = %lf \n",speedc);
   
   
   OMEGAMPI_MC.Write();
   KPM_MC.Write();
   KSL_MC.Write();
   THREEPIGAM_MC.Write();
   THREEPI_MC.Write();
   ETAGAM_MC.Write();
   BKGSUM1_MC.Write();
   BKGSUM2_MC.Write();
}

TLorentzVector MyClass::GetLorentzVector(TVector3 vector, Double_t mass) {
	TLorentzVector tvector(0.,0.,0.,0.);
	Double_t E=0.;
	
	E=TMath::Sqrt(TMath::Power(mass,2) + vector.Mag2());
	tvector.SetPxPyPzE(vector(0),vector(1),vector(2),E);
		
	return tvector;
}










