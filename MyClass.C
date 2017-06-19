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
	Int_t mctype_MC = 0;
	Double_t IMthreepi_MC = 0., Eisr_MC = 0.;
	Double_t chi2value = 0., pvalue = 0.;
	Double_t bestPiTime = 0., bestETime = 0.;
	Double_t deltaE = 0., tracksum = 0.;
	Double_t threepiIM_rec = 0., threepiIM = 0., threepiIM_impv = 0., IMdiff = 0.;
	Double_t threepiIM_nofit = 0.;
	Double_t isrE = 0., isrE_impv = 0.;
	Double_t Emaxprompt = 0., bestpiphoton1Ekinfit = 0., bestpiphoton2Ekinfit = 0., pionphotonEsum = 0.;
	Double_t pi0IM = 0., mggdiffmin = 0;
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
	TTree ALLCHAIN_MC("ALLCHAIN_MC","recreate");
	TTree ALLCHAIN_Pre("ALLCHAIN_Pre","recreate");
	
	TCollection* treelist = new TList; 
	treelist->Add(&OMEGAMPI_MC);
	treelist->Add(&KPM_MC);
	treelist->Add(&KSL_MC);
	treelist->Add(&THREEPIGAM_MC);
	treelist->Add(&THREEPI_MC);
	treelist->Add(&ETAGAM_MC); 
	treelist->Add(&BKGSUM1_MC); 
	treelist->Add(&BKGSUM2_MC); 
	treelist->Add(&ALLCHAIN_MC);
	TCollection* treelist1 = new TList; 
	treelist1->Add(&ALLCHAIN_Pre);
	// pre selected
	// define branches
	TString Smctype = getbraname(0);
	TString SIMthreepi = getbraname(1); std::cout<<getbraname(1)<<endl;
	TString SEisr = getbraname(2); std::cout<<getbraname(2)<<endl;
	TString SChi2value = getbraname(3); std::cout<<getbraname(3)<<endl; 
	TString SBestPiTime = getbraname(5); std::cout<<getbraname(5)<<endl;
	TString SBestETime = getbraname(6); std::cout<<getbraname(6)<<endl;
	TString SDeltaE = getbraname(7); std::cout<<getbraname(7)<<endl;
	TString STracksum = getbraname(8); std::cout<<getbraname(8)<<endl; 
	TString SThreepiIM = getbraname(9); std::cout<<getbraname(9)<<endl;
	TString SIMdiff = getbraname(10); std::cout<<getbraname(10)<<endl;
	TString SThreepiIM_impv = getbraname(11); std::cout<<getbraname(11)<<endl;
	TString SEmaxprompt = getbraname(12); std::cout<<getbraname(12)<<endl;
	TString SBestpiphoton1Ekinfit = getbraname(13); std::cout<<getbraname(13)<<endl;
	TString SBestpiphoton2Ekinfit = getbraname(14); std::cout<<getbraname(14)<<endl;
	TString SISRE = getbraname(15); getbraname(15); std::cout<<getbraname(15)<<endl;
	TString SISRE_impv = getbraname(16); getbraname(16); std::cout<<getbraname(16)<<endl; 
	TString SPionphotonEsum = getbraname(17); getbraname(17); std::cout<<getbraname(17)<<endl; 
	TString SThreepiIM_nofit = getbraname(18); getbraname(18); std::cout<<getbraname(18)<<endl;
	TString SMggdiffmin = getbraname(19); getbraname(19); std::cout<<getbraname(19)<<endl;
	TString SPi0IM = getbraname(20); getbraname(20); std::cout<<getbraname(20)<<endl; 
	TString SThreepiIM_rec = getbraname(22); getbraname(22); std::cout<<getbraname(22)<<endl;
	
	TObject* treeout=0;
	TIter treeliter(treelist);
	while((treeout=treeliter.Next()) !=0) {
		//treeout->Print();
		TTree* tree_temp=dynamic_cast<TTree*>(treeout);
		tree_temp->Branch(Smctype+"_MC",&mctype_MC,Smctype+"_MC/I");
		tree_temp->Branch(SIMthreepi+"_MC",&IMthreepi_MC,SIMthreepi+"_MC/D");
		tree_temp->Branch(SEisr+"_MC",&Eisr_MC,SEisr+"_MC/D");
	}
	
	TObject* treeout1=0;
	TIter treeliter1(treelist1);
	while((treeout1=treeliter1.Next()) !=0) {
		//treeout->Print();
		TTree* tree_temp=dynamic_cast<TTree*>(treeout1);
		tree_temp->Branch(Smctype+"_MC",&mctype_MC,Smctype+"_MC/I");
		tree_temp->Branch(SIMthreepi+"_MC",&IMthreepi_MC,SIMthreepi+"_MC/D");
		tree_temp->Branch(SEisr+"_MC",&Eisr_MC,SEisr+"_MC/D");
		tree_temp->Branch(SChi2value,&chi2value,SChi2value+"/D");
		tree_temp->Branch(SBestPiTime,&bestPiTime,SBestPiTime+"/D");
		tree_temp->Branch(SBestETime,&bestETime,SBestETime+"/D");
		tree_temp->Branch(SDeltaE,&deltaE,SDeltaE+"/D");
		tree_temp->Branch(STracksum,&tracksum,STracksum+"/D");
		tree_temp->Branch(SThreepiIM,&threepiIM,SThreepiIM+"/D");
		tree_temp->Branch(SThreepiIM_nofit,&threepiIM_nofit,SThreepiIM_nofit+"/D");
		tree_temp->Branch(SThreepiIM_impv,&threepiIM_impv,SThreepiIM_impv+"/D");
		tree_temp->Branch(SIMdiff,&IMdiff,SIMdiff+"/D");
		tree_temp->Branch(SEmaxprompt,&Emaxprompt,SIMdiff+"/D");
		tree_temp->Branch(SBestpiphoton1Ekinfit,&bestpiphoton1Ekinfit,SBestpiphoton1Ekinfit+"/D");
		tree_temp->Branch(SBestpiphoton2Ekinfit,&bestpiphoton2Ekinfit,SBestpiphoton2Ekinfit+"/D");
		tree_temp->Branch(SISRE,&isrE,SISRE+"/D");
		tree_temp->Branch(SISRE_impv,&isrE_impv,SISRE_impv+"/D");
		tree_temp->Branch(SPionphotonEsum,&pionphotonEsum,SPionphotonEsum+"/D");
		tree_temp->Branch(SMggdiffmin,&mggdiffmin,SMggdiffmin+"/D"); 
		tree_temp->Branch(SPi0IM,&pi0IM,SPi0IM+"/D");
		tree_temp->Branch(SThreepiIM_rec,&threepiIM_rec,SThreepiIM_rec+"/D");
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
      	mctype_MC = 1; 
      	IMthreepi_MC = 0.;
      	Eisr_MC = 0.;
      	OMEGAMPI_MC.Fill();
      }
      else if (phid == 1) {// kpm
      	mctype_MC = 2;  //cout<<mctype_MC<<endl;
      	IMthreepi_MC = 0.; 
      	Eisr_MC = 0.;
      	KPM_MC.Fill();
      }
      else if (phid == 2) {// ksl
      	mctype_MC = 3; 
      	IMthreepi_MC = 0.; 
      	Eisr_MC = 0.;
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
			   if (pi0nb == 1 && piplnb == 1 && piminb == 1 && isr1nb == 1 ) {// threepigam
			   	mctype_MC = 4;  
			      Eisr_MC=trueisr.E();			      
			      IMthreepi_MC = true3pi.M(); 	     
			      THREEPIGAM_MC.Fill();
      		}
      		else {
      			mctype_MC = 5;  // three pi
			      IMthreepi_MC = true3pi.M(); 
			      Eisr_MC=trueisr.E();
      			THREEPI_MC.Fill();
      		}
      	}
      	else {
      		mctype_MC=6;  
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
			   IMthreepi_MC = true3pi_eta.M(); 
			   Eisr_MC=trueisr_eta.E();		   
      		mctype_MC=7;  // eta gamma
      		//threepiIM_MC=true3pi_eta.M(); 
      		ETAGAM_MC.Fill();
      	}
      	else {
      		mctype_MC=8; 
      	}
      }	
      else {
      	mctype_MC=9; 
      }	
      
      
      if (mctype_MC==6 || mctype_MC==8 || mctype_MC==9 ) {
      	BKGSUM1_MC.Fill();
      }

		if (mctype_MC==2 || mctype_MC==3 || mctype_MC==5 || mctype_MC==6 ||  mctype_MC==8 || mctype_MC==9) {
      	BKGSUM2_MC.Fill();	
      }
      
      	
      
      ///
      TVector3 gammapos(0.,0.,0.);
		Double_t gammatheta = 0., rtsq = 0., rt = 0., xyres=1.2, zres = 1.4, eres_b = 0.057;
		Double_t eres_ec = 0.061, tres_a_bar = 0.055, tres_a_ec = 0.060, tres_b_bar = 0.147, tres_b_ec = 0.147;
		Double_t Emax_temp=0, Esum_temp=0., phoE_temp=0., phoEmin=1000000000.;
		Double_t EsumPrompt_temp=0., phoEPrompt_temp=0.;
		Double_t Rclus_temp=0, tclus_temp=0., tclusdiff_temp=0.;
		Int_t promptnb=0;
		Bool_t rightEprompt=kFALSE;
		for (Int_t k = 0; k < nclu; k++) {// loop over all clusters
			gammapos.SetXYZ(xcl[k]-bx, ycl[k]-by, zcl[k]-bz);
			Rclus_temp=gammapos.Mag();
			
			gammatheta=gammapos.Theta()*TMath::RadToDeg();
			if (enecl[k]>Emax_temp) {
				Emax_temp=enecl[k];
				tclusdiff_temp=Rclus_temp/(speedc*tcl[k]);
			}	
			//speedc
			Esum_temp=phoE_temp+enecl[k];
			phoE_temp=Esum_temp;
			if (charged_new[k] == 0 && intime[k] && enecl[k] >= egammamin && gammatheta > minangle && gammatheta < maxangle && mmclu[k] != 5) {
				EsumPrompt_temp=phoEPrompt_temp+enecl[k];
				phoEPrompt_temp=EsumPrompt_temp;
				if (enecl[k] > 50.) rightEprompt = kTRUE;	
				// select least cluster energy
				if (enecl[k] < phoEmin) {
					phoEmin=enecl[k];
				}						
				// E, x, y, z and t values
				E_candidates[promptnb] = enecl[k]; //cout<<E_candidates[promptnb]<<endl;
				X_candidates[promptnb] = xcl[k]-bx; // check bx, by, bz values
				Y_candidates[promptnb] = ycl[k]-by;
				Z_candidates[promptnb] = zcl[k]-bz;
				T_candidates[promptnb] = tcl[k];
				// sigma2 of E, x, y, z and t values
				rtsq = TMath::Power(xcl[k]-bx,2)+TMath::Power(ycl[k]-by,2);
				rt = TMath::Sqrt(rtsq);
				
				if (rt > 200.) {// hits on barrel
			      Sig2X_candidates[promptnb] = xyres*xyres;
			      Sig2Y_candidates[promptnb] = xyres*xyres;
				   Sig2Z_candidates[promptnb] = TMath::Power(zres*TMath::Sqrt(1000./enecl[k]),2);
				   Sig2T_candidates[promptnb] = TMath::Power(tres_a_bar*TMath::Sqrt(1000./enecl[k]),2)+TMath::Power(tres_b_bar,2); //1000./enecl[k]
				   Sig2E_candidates[promptnb] = TMath::Power(eres_b*TMath::Sqrt(1000.*enecl[k]),2);
				}
				else {// hits on end-cup 
					Sig2X_candidates[promptnb] = xyres*xyres;
					Sig2Z_candidates[promptnb] = xyres*xyres;
					Sig2Y_candidates[promptnb] = TMath::Power(zres*TMath::Sqrt(1000./enecl[k]),2);
					Sig2T_candidates[promptnb] = TMath::Power(tres_a_ec*TMath::Sqrt(1000./enecl[k]),2)+TMath::Power(tres_b_ec,2);
					Sig2E_candidates[promptnb] = TMath::Power(eres_ec*TMath::Sqrt(1000.*enecl[k]),2);
				}
				
				//printf("promptnb=%d: E=%1.4lf, x=%lf, y=%lf, z=%lf, t=%lf \n ",promptnb, E_candidates[promptnb], X_candidates[promptnb], Y_candidates[promptnb], Z_candidates[promptnb], T_candidates[promptnb]);
				promptnb++;
			}
		} 
		
		/// track info
		Float_t rpca = 0.0, delta_r=0.0, delta_z=0.0;
		for (Int_t k = 0; k < nt; k++) {
			rpca = sqrt(xpca[k]*xpca[k]+ypca[k]*ypca[k]);
			delta_r = sqrt((bx-xpca[k])*(bx-xpca[k]) + (by-ypca[k])*(by-ypca[k]));
			delta_z = bz-zpca[k];
			//hrdist->Fill(delta_r);
		}
		
		//
		Int_t prompttracknb = 0, trackindex1 = 0, trackindex2 = 0;
		TVectorD piontrnb(3);
		piontrnb = Getpiontrnb();
		prompttracknb = piontrnb(0), trackindex1 = piontrnb(1), trackindex2 = piontrnb(2);
		Bool_t if2PionTrack = If2PionTracks(prompttracknb, trackindex1, trackindex2);
		
		
		ALLCHAIN_MC.Fill();
		
		/// pre selection
      if (!if2PionTrack) continue; 
      if (!IfStreamed(pstrnb)) continue; 
      if (IfFiltered()) continue;
      if (promptnb != 3) continue; 
      
      
      // define vaiables of best obervables
		Double_t bestlagvalue=1000000000., bestpvalue=0., beamE=Beam.E(); //Beam.Print();
		Int_t Bestphotocandindex[3]={0,0,0};
		TVectorD bestinputvector(Row), bestsigma2vector(Row);
		TVectorD bestinputvectorkinfit(Row), bestsigma2vectorkinfit(Row);
		TVectorD pullsvector(Row), gkinfitinput(row);
		TMatrixD bestVkinfit(Row,Col);
		for (Int_t nr1 = 0; nr1 < promptnb-2; nr1++) {// select 3 photon loop
   		for (Int_t nr2 = nr1 + 1; nr2 < promptnb-1; nr2++) {
				for (Int_t nr3 = nr2 + 1; nr3 < promptnb; nr3++) {
				  //printf("nr1 = %d, nr2 = %d, nr3 = %d \n",nr1,nr2,nr3);
					Int_t Photocandindex_temp[3]={0,0,0};
					Photocandindex_temp[0]=nr1, Photocandindex_temp[1]=nr2, Photocandindex_temp[2]=nr3;								
							
					// kin.fit
					Double_t lagravaluekinfittildeloop=10000000000., lagravaluekinfitloop_temp=10000000000., lagravaluekinfitloop=10000000000., pvalueloop=0.;
					Int_t steploop=0, nfloop=7;
					TVectorD etatildekinfitloop(Row), etakinfitloop_temp(Row), etakinfitloop(Row), diffvectorkinfitloop(Row), lambdavectorloop(row);
					TVectorD gkinfitloop(row), gkinfitinput_temp(row), sigma2vectorkinfitloop(Row), pullsvectorloop(Row);
					TMatrixD Getakinfitloop(row,Col), Getakinfittransloop(Col,row), Skinfitloop(row,row), InSkinfitloop(row,row), 
					Vkinfitloop(Row,Col);
					// initialization
					TVectorD inputvectorloop=FillInputvector(Row, nr1, nr2, nr3, trackindex1, trackindex2);
					TVectorD sigma2vectorloop=FillSigma2vector(Row, nr1, nr2, nr3, trackindex1, trackindex2);
					TMatrixD Vmatrixloop=CovMatrix(sigma2vectorloop, Row, Col);
					etakinfitloop_temp=inputvectorloop, etakinfitloop=inputvectorloop; 
					//inputvectorloop.Print(); 
					//cout<<gvector_test(5)<<endl;
					gkinfitinput_temp=gfunc(inputvectorloop, row, Beam); 
					while (steploop<5) {
						etatildekinfitloop=etakinfitloop_temp; //etatildekinfitloop.Print();
						etakinfitloop_temp=etakinfitloop; //etakinfitloop_temp.Print();
						diffvectorkinfitloop=inputvectorloop-etatildekinfitloop;
		   			gkinfitloop=gfunc(etatildekinfitloop, row, Beam); //gkinfitloop.Print();
		   
		   			lagravaluekinfittildeloop=lagravaluekinfitloop_temp;
		   			lagravaluekinfitloop_temp=lagravaluekinfitloop;
		   
		   			Getakinfitloop=Getafunc(etatildekinfitloop, row, Col);
		   			Getakinfittransloop=Mtrans(Getakinfitloop);
		   			Skinfitloop=Getakinfitloop*(Vmatrixloop*Getakinfittransloop); 
		   			InSkinfitloop=MInvert(Skinfitloop);
		   			lambdavectorloop=Lambdavector(row, InSkinfitloop, Getakinfitloop, gkinfitloop, diffvectorkinfitloop);
		   
		   			lagravaluekinfitloop=lambdavectorloop*(Getakinfitloop*diffvectorkinfitloop+gkinfitloop); //cout<<lagravaluekinfitloop<<endl;
		   			lagravaluekinfitloop_temp=lagravaluekinfitloop;
		   			lagravaluekinfitloop=lagravaluekinfittildeloop;
		   
		   			Vkinfitloop=Vmatrixloop-Vmatrixloop*(Getakinfittransloop*InSkinfitloop*Getakinfitloop)*Vmatrixloop;		   
		   			sigma2vectorkinfitloop=Fillsigma2vectorkinfit(Row,Vkinfitloop,Col,Row);
		   			pullsvectorloop=Fillpullsvector(Row,sigma2vectorloop,sigma2vectorkinfitloop,inputvectorloop,etatildekinfitloop);
		   			etakinfitloop=etakinfitfunc(Vmatrixloop, Getakinfittransloop, lambdavectorloop, inputvectorloop, Row);
		   			etakinfitloop_temp=etakinfitloop;
						etakinfitloop=etatildekinfitloop;
				
						steploop++;
					}
					//printf("nr1=%d, nr2=%d, nr3=%d, chi2_temp=%lf \n", Photocandindex_temp[0],Photocandindex_temp[1],Photocandindex_temp[2], lagravaluekinfitloop_temp);
					if (lagravaluekinfitloop_temp<bestlagvalue) {// select input with minimum lagr value
						bestlagvalue=lagravaluekinfitloop_temp; chi2value=bestlagvalue;
						bestpvalue=TMath::Prob(bestlagvalue,nfloop); pvalue=bestpvalue;
						Bestphotocandindex[0]=Photocandindex_temp[0];
						Bestphotocandindex[1]=Photocandindex_temp[1];
						Bestphotocandindex[2]=Photocandindex_temp[2];
						bestinputvector=inputvectorloop;
						bestsigma2vector=sigma2vectorloop;
						bestsigma2vectorkinfit=sigma2vectorkinfitloop;
						bestinputvectorkinfit=etakinfitloop_temp;
						bestVkinfit=Vkinfitloop;
						pullsvector=pullsvectorloop;
						gkinfitinput=gkinfitinput_temp;
					}// end selection
				}
			}
		}// select 3 photon loop
		
		// not fitted
		TLorentzVector bestphoton1=Getphoton4vector(bestinputvector(0),bestinputvector(1),bestinputvector(2),bestinputvector(3));
		TLorentzVector bestphoton2=Getphoton4vector(bestinputvector(5),bestinputvector(6),bestinputvector(7),bestinputvector(8));
		TLorentzVector bestphoton3=Getphoton4vector(bestinputvector(10),bestinputvector(11),bestinputvector(12),bestinputvector(13));
		TLorentzVector bestppl=Gettrack4vectorkinfit(bestinputvector(15), bestinputvector(16), bestinputvector(17));
		TLorentzVector bestpmi=Gettrack4vectorkinfit(bestinputvector(18), bestinputvector(19), bestinputvector(20));
		
		// fitted
		TLorentzVector bestphoton1kinfit=Getphoton4vector(bestinputvectorkinfit(0),bestinputvectorkinfit(1),bestinputvectorkinfit(2),bestinputvectorkinfit(3));
		TLorentzVector bestphoton2kinfit=Getphoton4vector(bestinputvectorkinfit(5),bestinputvectorkinfit(6),bestinputvectorkinfit(7),bestinputvectorkinfit(8));
		TLorentzVector bestphoton3kinfit=Getphoton4vector(bestinputvectorkinfit(10),bestinputvectorkinfit(11),bestinputvectorkinfit(12),bestinputvectorkinfit(13));
		TLorentzVector bestpplkinfit=Gettrack4vectorkinfit(bestinputvectorkinfit(15), bestinputvectorkinfit(16), bestinputvectorkinfit(17));
		TLorentzVector bestpmikinfit=Gettrack4vectorkinfit(bestinputvectorkinfit(18), bestinputvectorkinfit(19), bestinputvectorkinfit(20));
		
		// Emax prompt photon
		TLorentzVector bestpiphoton1kinfit, bestpiphoton2kinfit;
		TLorentzVector Emaxprompt4mom;
		Double_t Emaxprompt_temp = 0.;
		if (bestphoton1kinfit.E() >= bestphoton2kinfit.E()) {
		  Emaxprompt_temp=bestphoton1kinfit.E();
		  bestpiphoton1kinfit = bestphoton2kinfit;
		  if (Emaxprompt_temp >= bestphoton3kinfit.E()) {
		  		Emaxprompt = Emaxprompt_temp;	
		  		Emaxprompt4mom = bestphoton1;
		  		bestpiphoton2kinfit = bestphoton3kinfit;		  		
		  }
		  else {
		  		Emaxprompt4mom = bestphoton3;
		  		Emaxprompt = bestphoton3kinfit.E();
		  		bestpiphoton2kinfit = bestphoton1kinfit;
		  }
		}  
		else {
		  Emaxprompt_temp=bestphoton2kinfit.E();
		  bestpiphoton1kinfit = bestphoton1kinfit;
		  if (Emaxprompt_temp >= bestphoton3kinfit.E()) {
		  		Emaxprompt = Emaxprompt_temp;	
		  		Emaxprompt4mom = bestphoton2;
		  		bestpiphoton2kinfit = bestphoton3kinfit;	
		  }
		  else {
		  		Emaxprompt = bestphoton3kinfit.E();
		  		Emaxprompt4mom = bestphoton3;
		  		bestpiphoton2kinfit = bestphoton2kinfit;
		  }
		}
		bestpiphoton1Ekinfit=bestpiphoton1kinfit.E();
		bestpiphoton2Ekinfit=bestpiphoton2kinfit.E();
		
		//time-of-fligt
		TVector2 bestppltime(2.0,-6.0), bestpmitime(2.0,-6.0);
		bestppltime.Set(timinginfo(trackindex1,bestppl)); // ppltime.Print();
		bestpmitime.Set(timinginfo(trackindex2,bestpmi));
		bestPiTime=bestppltime.X(), bestETime=bestppltime.Y();
		
		//deltaE and tracksum
		tracksum = (bestpplkinfit.Vect()).Mag()+(bestpmikinfit.Vect()).Mag();
		
		Double_t pionMsqr=TMath::Power(masschpion,2);
		Double_t pplmomsqr=TMath::Power((bestpplkinfit.Vect()).Mag(),2);
		Double_t pmimomsqr=TMath::Power((bestpmikinfit.Vect()).Mag(),2);
		deltaE = (bestpplkinfit.Vect()+bestpmikinfit.Vect()-Beam.Vect()).Mag()-(Beam.E()-TMath::Sqrt(pionMsqr+pplmomsqr)-TMath::Sqrt(pionMsqr+pmimomsqr));
		
		/// permutation
      Int_t permunb=0, permunbmin=0;
   	Double_t chi2Eisromega_temp=0., chi2Eisreta_temp=0., chi2mgg_temp=0.;
   	Double_t chi2test_temp=0., chi2testmin=1000000000., chi2testmin1=1000000000.;
   	Double_t boostangle=0., anglediff=0.;
   	TVectorD inputvectormin(Row), inputvectorminkinfit(Row), sigma2vectormin(Row);
   	TVectorD inputvectormin1(Row), inputvectorminkinfit1(Row);
   	TVectorD inputvector_permu(Row), sigma2vector_permu(Row);
   	TVectorD inputvectorkinfit_permu(Row), sigma2vectorkinfit_permu(Row);
   	TLorentzVector pionphoton1_temp(0.,0.,0.,0.), pionphoton2_temp(0.,0.,0.,0.), isrphoton_temp(0.,0.,0.,0.);
   	TLorentzVector pionphoton1boost_temp(0.,0.,0.,0.), pionphoton2boost_temp(0.,0.,0.,0.), isrphotonboost_temp(0.,0.,0.,0.);
   	TLorentzVector pionphoton1min(0.,0.,0.,0.), pionphoton2min(0.,0.,0.,0.), isrphotonmin(0.,0.,0.,0.), threepiboost(0.,0.,0.,0.), bestpplboost(0.,0.,0.,0.), bestpmiboost(0.,0.,0.,0.);
   	
   	for (Int_t j=0;j<2;j++) {// begin permu. loop
			//printf("j=%d, photon2 index=%d\n",j,Photocandindex[j]);
			for (Int_t k=j+1;k<3;k++) {
				//printf("(j=%d, k=%d)\n",j,k);
				for (Int_t i=0;i<3;i++) {
					if (i!=j && i!=k) {
						permunb++;
						Double_t sigma12=bestVkinfit(5*j,5*k); //cout<<sigma12<<endl;
						// not fitted
						inputvector_permu=Fillpermutvector(Row,bestinputvector,i,j,k); //inputvector_permu.Print();
						sigma2vector_permu=Fillpermutvector(Row,bestsigma2vector,i,j,k);
						
						// fitted
						inputvectorkinfit_permu=Fillpermutvector(Row,bestinputvectorkinfit,i,j,k);
						sigma2vectorkinfit_permu=Fillpermutvector(Row,bestsigma2vectorkinfit,i,j,k);
						//chi2 test on invariant mass of two photons, fill pion photons 4 vectors						
						pionphoton1_temp=Getphoton4vector(inputvector_permu(5),inputvector_permu(6),inputvector_permu(7),inputvector_permu(8)); //cout<<pionphoton1_temp.E()<<endl;
						pionphoton2_temp=Getphoton4vector(inputvector_permu(10),inputvector_permu(11),inputvector_permu(12),inputvector_permu(13));
						isrphoton_temp=Getphoton4vector(inputvector_permu(0),inputvector_permu(1),inputvector_permu(2),inputvector_permu(3));
						//
						pionphoton1boost_temp=pionphoton1_temp;
						pionphoton1boost_temp.Boost(Boost3vector);
						//
						pionphoton2boost_temp=pionphoton2_temp;
						pionphoton2boost_temp.Boost(Boost3vector);
						//
						isrphotonboost_temp=isrphoton_temp;
						isrphotonboost_temp.Boost(Boost3vector);
						//
						bestpplboost=bestpplkinfit;
						bestpplboost.Boost(Boost3vector);
						//
						bestpmiboost=bestpmikinfit;
						bestpmiboost.Boost(Boost3vector);
						
						threepiboost=pionphoton1boost_temp+pionphoton2boost_temp+bestpplboost+bestpmiboost;
						boostangle=threepiboost.Angle(isrphotonboost_temp.Vect())*180./pi;
						anglediff=boostangle-180.;
	
						//cout<<boostangle<<endl;
						//pionphoton1boost_temp.Print();
						Double_t openangle=pionphoton1_temp.Angle(pionphoton2_temp.Vect());
						Double_t cosangle=TMath::Cos(openangle);
						//Double_t mgg_temp=TMath::Sqrt(2*pionphoton1_temp.E()*pionphoton2_temp.E()*(1-cosangle));
						Double_t mgg_temp=(pionphoton1_temp+pionphoton2_temp).M();
						//Double_t mgg=(pionphoton1_temp+pionphoton2_temp).M(); //hIMtest->Fill(mgg_temp);
						//cout<<mgg<<endl;
						//
						Double_t errormggsq=TMath::Power(mgg_temp/2,2)*(sigma2vector_permu(5)/TMath::Power(inputvector_permu(5),2)+sigma2vector_permu(10)/TMath::Power(inputvector_permu(10),2));
						Double_t msq=TMath::Power(mgg_temp,2);
						//Double_t errormggsq=TMath::Power(msq,2)*(sigma2vector_permu(5)/TMath::Power(inputvector_permu(5),2)+sigma2vector_permu(10)/TMath::Power(inputvector_permu(10),2));
						//
						Double_t chi2Eisreta_temp=Chi2Eisrtest(inputvector_permu,sigma2vector_permu,363.);
						Double_t chi2Eisromega_temp=Chi2Eisrtest(inputvector_permu,sigma2vector_permu,209.);
						Double_t chi2diff=chi2Eisromega_temp-chi2Eisreta_temp;						
						//
						Double_t mggdiff_temp=mgg_temp-massneupion;
						//Double_t mggdiff_temp=TMath::Power(mgg_temp,2)-TMath::Power(massneupion,2);
						//
						TLorentzVector threepions_temp=pionphoton1_temp+pionphoton2_temp+bestppl+bestpmi;
						Double_t beta_temp=(threepions_temp.Vect()).Mag()/threepions_temp.E();
						Double_t betadiff=beta_temp-0.264;
						//Double_t chi2mgg_temp=TMath::Power(mggdiff_temp,2);
						Double_t chi2mgg_temp=TMath::Power(mggdiff_temp,2)/errormggsq;
   					//Double_t chi2mgg_temp=TMath::Power(mggdiff_temp,2)/errormggsq+chi2Eisromega_temp;
   					//Double_t chi2mgg_temp=TMath::Power(mggdiff_temp,2)/errormggsq+TMath::Power(anglediff,2)/180.;
   					//if (chi2diff < 0.) chi2mgg_temp=chi2Eisromega_temp;
   					//else chi2mgg_temp=chi2Eisreta_temp;
   					//
   					Double_t chi2mgg_temp1=TMath::Power(mggdiff_temp,2)/errormggsq+chi2Eisreta_temp;
   					//cout<<chi2mgg_temp<<endl;
   					//inputvector_permu.Print();
   					//cout<<pionphoton1_temp.E()<<endl;
   					//cout<<pionphoton2_temp.E()<<endl;
   					if (chi2mgg_temp < chi2testmin) {
							chi2testmin=chi2mgg_temp; 
							permunbmin=permunb;
							inputvectormin=inputvector_permu;
							inputvectorminkinfit=inputvectorkinfit_permu;
							sigma2vectormin=sigma2vectorkinfit_permu;
							pionphoton1min=pionphoton1_temp; //pionphoton1min.Print();
							pionphoton2min=pionphoton2_temp; //pionphoton2min.Print();
							isrphotonmin=isrphoton_temp; //isrphotonmin.Print();
						}// end selection
						// improve eta selection
						if (chi2mgg_temp1 < chi2testmin1) {
						   chi2testmin1=chi2mgg_temp1; 
							permunbmin=permunb;
							inputvectormin1=inputvector_permu;
							inputvectorminkinfit1=inputvectorkinfit_permu; //cout<<inputvectorminkinfit1(0)<<endl;
						}
					}	 								
				}
			}		
		}// end permu. loop
		
		// not fitted
		TLorentzVector ISRphoton=Getphoton4vector(inputvectormin(0),inputvectormin(1),inputvectormin(2),inputvectormin(3)); //cout<<ISRphoton.E()<<endl;
		TLorentzVector pionphoton1=Getphoton4vector(inputvectormin(5),inputvectormin(6),inputvectormin(7),inputvectormin(8));
		TLorentzVector pionphoton2=Getphoton4vector(inputvectormin(10),inputvectormin(11),inputvectormin(12),inputvectormin(13));
		TLorentzVector threepions=pionphoton1+pionphoton2+bestppl+bestpmi;
		threepiIM_nofit=(Beam-ISRphoton).M();
		
		// fitted
		TLorentzVector ISRphotonkinfit=Getphoton4vector(inputvectorminkinfit(0),inputvectorminkinfit(1),inputvectorminkinfit(2),inputvectorminkinfit(3));
		TLorentzVector pionphoton1kinfit=Getphoton4vector(inputvectorminkinfit(5),inputvectorminkinfit(6),inputvectorminkinfit(7),inputvectorminkinfit(8));
		TLorentzVector pionphoton2kinfit=Getphoton4vector(inputvectorminkinfit(10),inputvectorminkinfit(11),inputvectorminkinfit(12),inputvectorminkinfit(13));
		TLorentzVector threepionskinfit=pionphoton1kinfit+pionphoton2kinfit+bestpplkinfit+bestpmikinfit;
		threepiIM_rec=(Beam-pionphoton1kinfit-pionphoton2kinfit).M();
		threepiIM=threepionskinfit.M();
		IMdiff = threepiIM-IMthreepi_MC;
		isrE = ISRphotonkinfit.E();
		pionphotonEsum = (pionphoton1kinfit.Vect()).Mag()+(pionphoton2kinfit.Vect()).Mag();
		pi0IM = (pionphoton1kinfit+pionphoton2kinfit).M();
		mggdiffmin=pi0IM-massneupion;
		
		/// improved eta IM selection
		// fitted		
		TLorentzVector ISRphotonkinfit1=Getphoton4vector(inputvectorminkinfit1(0),inputvectorminkinfit1(1),inputvectorminkinfit1(2),inputvectorminkinfit1(3));
		TLorentzVector pionphoton1kinfit1=Getphoton4vector(inputvectorminkinfit1(5),inputvectorminkinfit1(6),inputvectorminkinfit1(7),inputvectorminkinfit1(8));
		TLorentzVector pionphoton2kinfit1=Getphoton4vector(inputvectorminkinfit1(10),inputvectorminkinfit1(11),inputvectorminkinfit1(12),inputvectorminkinfit1(13));
		TLorentzVector threepionskinfit1=pionphoton1kinfit1+pionphoton2kinfit1+bestpplkinfit+bestpmikinfit;
		threepiIM_impv=threepionskinfit1.M();
		isrE_impv = ISRphotonkinfit1.E();
		
		ALLCHAIN_Pre.Fill();
		
      
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
   ALLCHAIN_MC.Write();
   ALLCHAIN_Pre.Write();
}

TLorentzVector MyClass::GetLorentzVector(TVector3 vector, Double_t mass) {
	TLorentzVector tvector(0.,0.,0.,0.);
	Double_t E=0.;
	
	E=TMath::Sqrt(TMath::Power(mass,2) + vector.Mag2());
	tvector.SetPxPyPzE(vector(0),vector(1),vector(2),E);
		
	return tvector;
}

TVectorD MyClass::Getpiontrnb() {
	TVectorD indexvector(3); 
	Int_t svar_pos = 0, svar_neg = 0, index1 = 0, index2 = 0;
	Float_t distance1 = 1000000.0, distance2 = 100000.0;
	Float_t dist = 0.0;
	
	for (Int_t k = 0; k < nt; k++) {// begin loop
		dist = sqrt((bx-xpca[k])*(bx-xpca[k]) + (by-ypca[k])*(by-ypca[k]) +(bz-zpca[k])*(bz-zpca[k]));
		if (curpca[k] < 0 && dist < distance1) {
			distance1 = dist;
			index1 = k;
			svar_neg=1;
		}
		else if (curpca[k] > 0 && dist < distance2) {
			distance2 = dist;
			index2 = k;
			svar_pos=1;
		}
	}// end loop
	
	indexvector(0) = svar_neg+svar_pos;
	indexvector(1) = index1; 
	indexvector(2) = index2; //indexvector.Print();
	
	return indexvector;
}

Bool_t MyClass::If2PionTracks(Int_t trnb, Int_t idx1, Int_t idx2) {
   Bool_t isbroken=kFALSE, isbroken1=kFALSE;
   if (TMath::Abs(cot[idx1] + cot[idx2]) < 0.1 && TMath::Abs((cur[idx1] + cur[idx2]) / cur[idx1]) < 0.2) isbroken=kTRUE;
   if (best_clu[idx1]==0 || best_clu[idx2]==0) {
   	//cout<<tcl[best_clu[idx1]-1]<<endl;
   	isbroken1=kTRUE;
   }
   if (isbroken || trnb<2. ) return kFALSE;
   else return kTRUE;
}


Bool_t MyClass::IfStreamed(Int_t pstrnb) {
	Bool_t bTagged=kFALSE, kstag = kFALSE;
	
	for (Int_t NrEC=0; NrEC<necls; NrEC++){
		if (eclstream[NrEC]==pstrnb) bTagged = kTRUE;
		//if((ecltagnum[NrEC] &  2 )==2 || (ecltagnum[NrEC] &  1 )==1 || (ecltagnum[NrEC] &  4 )==4 || (ecltagnum[NrEC] &  8 )==8 || (ecltagnum[NrEC] &  16 )==16) {
		if((ecltagnum[NrEC] &  1 )==1) {
		  kstag = kTRUE;
		  //if (j>0) continue; 
		  /*printf("decimal=%d\n",ecltagnum[NrEC]);
		  std::string r;
		  Int_t i=0;
		  while(ecltagnum[NrEC]!=0) {
		    r=(ecltagnum[NrEC]%2==0 ?"0":"1")+r; 
		    ecltagnum[NrEC]/=2;
		    }
		  std::cout<<r<<endl;
		  printf("===============\n");
		  //cout<<ecltagnum[NrEC]<<endl;*/
		  /*int bank[20];
      int total=-1;
      int ecltagnum_temp=ecltagnum[NrEC];
      for(int q=0;ecltagnum_temp>0;q++){
        if((ecltagnum_temp%2) == 0)
          bank[q]=0;
        else 
          bank[q]=1;
      total++;
      ecltagnum_temp/=2;
      }
      //cout<<"Number binary = "; 
      for(int w=total;w>=0;w--) 
      {
        //cout<<bank[w];
        //printf("w=%d ",w);
        if(bank[w])htag->Fill(w,1);
      }
      //cout<<endl;*/
		}  
  }

	//if (bTagged && kstag) return kTRUE;
	if (bTagged) return kTRUE;
	else return kFALSE;
}

Bool_t MyClass::IfFiltered() {
	Bool_t passfilfo=kFALSE, passtrigger=kFALSE;
   
	if (((eclfilfo & ( 1 << 20 )) >> 20) == 1) passfilfo=kTRUE;
	if (trgtype == 2 || trgtype == 6 ) passtrigger = kTRUE;
	//if (trgtype !=0 ) passtrigger = kTRUE;

	if (passfilfo && passtrigger) return kFALSE;
	//if (passfilfo) return kFALSE;
	else return kTRUE;
}

TVectorD MyClass::FillInputvector(Int_t size, Int_t index1, Int_t index2, Int_t index3, Int_t indtr1, Int_t indtr2) {
	TVectorD vector(size);
	Double_t inputarray[21] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
	Double_t r1sq=0., r2sq=0., r3sq=0., pp1sq=0., pp2sq=0.;
	Double_t r1=0., r2=0., r3=0., px1=0., px2=0., px3=0., py1=0., py2=0., py3=0., pz1=0., pz2=0., pz3=0.;
	Double_t Epp1=0., Epp2=0., pp1=0., pp2=0., ppx1=0., ppx2=0., ppy1=0., ppy2=0., ppz1=0., ppz2=0., pp1tran=0., pp2tran=0.;
	Double_t x1=0., x2=0., x3=0., y1=0., y2=0., y3=0., z1=0., z2=0., z3=0., E1=0., E2=0., E3=0., t1=0., t2=0., t3=0.;
	
	// calulate x1, x2, x3, y1, y2, y3, z1, z2, z3
	// calulate E1, E2, E3, t1, t2, t3
	// calulate px1, px2, px3
	x1=X_candidates[index1], x2=X_candidates[index2], x3=X_candidates[index3];
	y1=Y_candidates[index1], y2=Y_candidates[index2], y3=Y_candidates[index3];
	z1=Z_candidates[index1], z2=Z_candidates[index2], z3=Z_candidates[index3];
			
	E1=E_candidates[index1], E2=E_candidates[index2], E3=E_candidates[index3];
	t1=T_candidates[index1], t2=T_candidates[index2], t3=T_candidates[index3];					
					

	// calculate squared r1sq, r2sq, r3sq and calculate r1, r2, r3
	r1sq=TMath::Power(x1,2.)+TMath::Power(y1,2.)+TMath::Power(z1,2.);			
	r2sq=TMath::Power(x2,2.)+TMath::Power(y2,2.)+TMath::Power(z2,2.);	
	r3sq=TMath::Power(x3,2.)+TMath::Power(y3,2.)+TMath::Power(z3,2.);	

	r1=TMath::Sqrt(r1sq), r2=TMath::Sqrt(r2sq), r3=TMath::Sqrt(r3sq);
					
	px1=E1*x1/r1, px2=E2*x2/r2, px3=E3*x3/r3;
	py1=E1*y1/r1, py2=E2*y2/r2, py3=E3*y3/r3;
	pz1=E1*z1/r1, pz2=E2*z2/r2, pz3=E3*z3/r3;
					
	// calulate ppx1, ppx2, ppy1, ppy2, ppz1, ppz2;

	// calculate squared ppx1sq, ppx2s, pp1tran, pp2tran, pp1, pp2, Epp1, Epp2
	// ppi1.SetX(ptransvSmeared * TMath::Cos(phipca[index]));
  	//	ppi1.SetY(ptransvSmeared * TMath::Sin(phipca[index]));
  	//	ppi1.SetZ(ptransvSmeared * cotpca[index]); 
 
	pp1tran=1000.*TMath::Abs(1./curpca[indtr1]);
	pp2tran=1000.*TMath::Abs(1./curpca[indtr2]);

	ppx1=pp1tran*TMath::Cos(phipca[indtr1]);
	ppx2=pp2tran*TMath::Cos(phipca[indtr2]);

	ppy1=pp1tran*TMath::Sin(phipca[indtr1]);
	ppy2=pp2tran*TMath::Sin(phipca[indtr2]);

	ppz1=pp1tran*cotpca[indtr1];
	ppz2=pp2tran*cotpca[indtr2];

	pp1sq=TMath::Power(ppx1,2)+TMath::Power(ppy1,2)+TMath::Power(ppz1,2);
	pp2sq=TMath::Power(ppx2,2)+TMath::Power(ppy2,2)+TMath::Power(ppz2,2);
		
	Epp1=TMath::Sqrt(masschpion*masschpion+pp1sq);
	Epp2=TMath::Sqrt(masschpion*masschpion+pp2sq);

	pp1=TMath::Sqrt(pp1sq);
	pp2=TMath::Sqrt(pp2sq);

	// measurements array
	inputarray[0]=E1, inputarray[1]=x1, inputarray[2]=y1, inputarray[3]=z1, inputarray[4]=t1; //cout<<inputarray[4]<<endl;
	inputarray[5]=E2, inputarray[6]=x2, inputarray[7]=y2, inputarray[8]=z2, inputarray[9]=t2;
	inputarray[10]=E3, inputarray[11]=x3, inputarray[12]=y3, inputarray[13]=z3, inputarray[14]=t3;
	inputarray[15]=TMath::Abs(curpca[indtr1]), inputarray[16]=cotpca[indtr1], inputarray[17]=phipca[indtr1];
	inputarray[18]=TMath::Abs(curpca[indtr2]), inputarray[19]=cotpca[indtr2], inputarray[20]=phipca[indtr2]; 
	return vector.Use(size,inputarray);
}

TVectorD MyClass::FillSigma2vector(Int_t size, Int_t index1, Int_t index2, Int_t index3, Int_t indtr1, Int_t indtr2) {
	TVectorD vector(size);
	Double_t sigma2array[21]={0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
	
	// fill sigma2 array
	sigma2array[0]=Sig2E_candidates[index1], sigma2array[1]=Sig2X_candidates[index1], sigma2array[2]=Sig2Y_candidates[index1], sigma2array[3]=Sig2Z_candidates[index1], sigma2array[4]=Sig2T_candidates[index1];
	sigma2array[5]=Sig2E_candidates[index2], sigma2array[6]=Sig2X_candidates[index2], sigma2array[7]=Sig2Y_candidates[index2], sigma2array[8]=Sig2Z_candidates[index2], sigma2array[9]=Sig2T_candidates[index2];
	sigma2array[10]=Sig2E_candidates[index3], sigma2array[11]=Sig2X_candidates[index3], sigma2array[12]=Sig2Y_candidates[index3], sigma2array[13]=Sig2Z_candidates[index3], sigma2array[14]=Sig2T_candidates[index3];
	sigma2array[15]=sigcurv[indtr1]/1000000., sigma2array[16]=sigcot[indtr1], sigma2array[17]=sigphi[indtr1];
	sigma2array[18]=sigcurv[indtr2]/1000000., sigma2array[19]=sigcot[indtr2], sigma2array[20]=sigphi[indtr2];
	
	return vector.Use(size,sigma2array);
}

TMatrixD MyClass::CovMatrix(TVectorD vector, Int_t row, Int_t col) {
	TMatrixD covmatrix_temp(row,col);

	for (Int_t i = 0; i < row; i++) {
  	for (Int_t j = 0; j < col; j++) {
			if (i==j) covmatrix_temp(i,j)=vector(i);
		}
  }
	return covmatrix_temp;
}

TVectorD MyClass::gfunc(TVectorD etavector, Int_t rownb, TLorentzVector beam) {
	TVectorD vector(rownb);
	//Double_t Beam_E=benergy;
	//beam.Print();

	Double_t r1sq=0., r2sq=0., r3sq=0., pp1sq=0., pp2sq=0.;
	Double_t r1=0., r2=0., r3=0., px1=0., px2=0., px3=0., py1=0., py2=0., py3=0., pz1=0., pz2=0., pz3=0.;
	Double_t Epp1=0., Epp2=0., pp1=0., pp2=0., ppx1=0., ppx2=0., ppy1=0., ppy2=0., ppz1=0., ppz2=0., pp1tran=0., pp2tran=0.;
	Double_t curv1=0., cotan1=0., phi1=0, curv2=0., cotan2=0., phi2=0;
	Double_t x1=0., x2=0., x3=0., y1=0., y2=0., y3=0., z1=0., z2=0., z3=0., E1=0., E2=0., E3=0., t1=0., t2=0., t3=0.;
	Double_t garray[7] = {0.,0.,0.,0.,0.,0.,0.};

	E1=etavector(0), x1=etavector(1), y1=etavector(2), z1=etavector(3), t1=etavector(4);
	E2=etavector(5), x2=etavector(6), y2=etavector(7), z2=etavector(8), t2=etavector(9);
	E3=etavector(10), x3=etavector(11), y3=etavector(12), z3=etavector(13), t3=etavector(14);

	// calculate squared r1sq, r2sq, r3sq and calculate r1, r2, r3
	r1sq=TMath::Power(x1,2.)+TMath::Power(y1,2.)+TMath::Power(z1,2.);			
	r2sq=TMath::Power(x2,2.)+TMath::Power(y2,2.)+TMath::Power(z2,2.);	
	r3sq=TMath::Power(x3,2.)+TMath::Power(y3,2.)+TMath::Power(z3,2.);	

	r1=TMath::Sqrt(r1sq), r2=TMath::Sqrt(r2sq), r3=TMath::Sqrt(r3sq); 

	px1=E1*x1/r1, px2=E2*x2/r2, px3=E3*x3/r3;
	py1=E1*y1/r1, py2=E2*y2/r2, py3=E3*y3/r3;
	pz1=E1*z1/r1, pz2=E2*z2/r2, pz3=E3*z3/r3;
	
	// calculate squared ppx1sq, ppx2s, pp1tran, pp2tran, pp1, pp2, Epp1, Epp2
	// ppi1.SetX(ptransvSmeared * TMath::Cos(phipca[index]));
   //	ppi1.SetY(ptransvSmeared * TMath::Sin(phipca[index]));
   //	ppi1.SetZ(ptransvSmeared * cotpca[index]); 
	curv1=etavector(15), cotan1=etavector(16), phi1=etavector(17);
	curv2=etavector(18), cotan2=etavector(19), phi2=etavector(20);
	//cout<<curv2-TMath::Abs(curpca[indtr2])<<endl;
	//cout<<cotan2-cotpca[indtr2]<<endl;
	//cout<<phi2-phipca[indtr2]<<endl;
	pp1tran=1000.*1./curv1;
	pp2tran=1000.*1./curv2;

	ppx1=pp1tran*TMath::Cos(phi1);
	ppx2=pp2tran*TMath::Cos(phi2);

	ppy1=pp1tran*TMath::Sin(phi1);
	ppy2=pp2tran*TMath::Sin(phi2);

	ppz1=pp1tran*cotan1;
	ppz2=pp2tran*cotan2;

	pp1sq=TMath::Power(ppx1,2.)+TMath::Power(ppy1,2.)+TMath::Power(ppz1,2.);
	pp2sq=TMath::Power(ppx2,2.)+TMath::Power(ppy2,2.)+TMath::Power(ppz2,2.);
		
	Epp1=TMath::Sqrt(masschpion*masschpion+pp1sq);
	Epp2=TMath::Sqrt(masschpion*masschpion+pp2sq);

	pp1=TMath::Sqrt(pp1sq);
	pp2=TMath::Sqrt(pp2sq);

	garray[0]=E1+E2+E3+Epp2+Epp1-beam.E(); //cout<<"Beam E="<<beam.E()<<endl;
	garray[1]=px1+px2+px3+ppx1+ppx2-beam.X(); 
	garray[2]=py1+py2+py3+ppy1+ppy2-beam.Y(); 
	garray[3]=pz1+pz2+pz3+ppz1+ppz2-beam.Z(); 
	garray[4]=r1-speedc*t1; 
	garray[5]=r2-speedc*t2; //cout<<garray[5]<<endl;
	garray[6]=r3-speedc*t3; 

	vector.Use(rownb,garray); 

	return vector;
}

TMatrixD MyClass::Getafunc(TVectorD etavector, Int_t rownb, Int_t colnb) {
	TMatrixD matrix_temp(rownb, colnb); 
	Double_t dg1deta[21] = {1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
	Double_t dg2deta[21] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
	Double_t dg3deta[21] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
	Double_t dg4deta[21] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
	Double_t dg5deta[21] = {0.,0.,0.,0.,-speedc,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
	Double_t dg6deta[21] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,-speedc,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
	Double_t dg7deta[21] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,-speedc,0.,0.,0.,0.,0.,0.}; 
	Double_t r1sq=0., r2sq=0., r3sq=0., pp1sq=0., pp2sq=0.;
	Double_t r1=0., r2=0., r3=0., px1=0., px2=0., px3=0., py1=0., py2=0., py3=0., pz1=0., pz2=0., pz3=0.;
	Double_t Epp1=0., Epp2=0., pp1=0., pp2=0., ppx1=0., ppx2=0., ppy1=0., ppy2=0., ppz1=0., ppz2=0., pp1tran=0., pp2tran=0.;
	Double_t curv1=0., cotan1=0., phi1=0, curv2=0., cotan2=0., phi2=0;
	Double_t x1=0., x2=0., x3=0., y1=0., y2=0., y3=0., z1=0., z2=0., z3=0., E1=0., E2=0., E3=0., t1=0., t2=0., t3=0.;
	TVectorD dg1(colnb), dg2(colnb), dg3(colnb), dg4(colnb), dg5(colnb), dg6(colnb), dg7(colnb);
	TVectorD dgarray[7]={dg1, dg2, dg3, dg4, dg5, dg6, dg7};
	Double_t hatE1=0., hatE2=0., hatE3=0, hatx1=0., hatx2=0., hatx3=0., haty1=0., haty2=0., haty3=0., hatz1=0., hatz2=0., hatz3=0.;
	

	// calulate x1, x2, x3, y1, y2, y3, z1, z2, z3
	// calulate E1, E2, E3, t1, t2, t3
	// calulate px1, px2, px3
	// calculate squared r1sq, r2sq, r3sq and calculate r1, r2, r3
	x1=etavector(1), x2=etavector(6), x3=etavector(11);
	y1=etavector(2), y2=etavector(7), y3=etavector(12);
	z1=etavector(3), z2=etavector(8), z3=etavector(13);
			
	E1=etavector(0), E2=etavector(5), E3=etavector(10);
	t1=etavector(4), t2=etavector(9), t3=etavector(14);
	
	r1sq=TMath::Power(x1,2.)+TMath::Power(y1,2.)+TMath::Power(z1,2.);			
	r2sq=TMath::Power(x2,2.)+TMath::Power(y2,2.)+TMath::Power(z2,2.);	
	r3sq=TMath::Power(x3,2.)+TMath::Power(y3,2.)+TMath::Power(z3,2.);	

	r1=TMath::Sqrt(r1sq), r2=TMath::Sqrt(r2sq), r3=TMath::Sqrt(r3sq);

	px1=E1*x1/r1, px2=E2*x2/r2, px3=E3*x3/r3;
	py1=E1*y1/r1, py2=E2*y2/r2, py3=E3*y3/r3;
	pz1=E1*z1/r1, pz2=E2*z2/r2, pz3=E3*z3/r3;
					
	// calulate ppx1, ppx2, ppy1, ppy2, ppz1, ppz2;
	// calculate squared ppx1sq, ppx2s, pp1tran, pp2tran, pp1, pp2, Epp1, Epp2
	curv1=etavector(15), cotan1=etavector(16), phi1=etavector(17);
	curv2=etavector(18), cotan2=etavector(19), phi2=etavector(20);
	
	pp1tran=1000.*1./curv1;
	pp2tran=1000.*1./curv2;

	ppx1=pp1tran*TMath::Cos(phi1);
	ppx2=pp2tran*TMath::Cos(phi2);

	ppy1=pp1tran*TMath::Sin(phi1);
	ppy2=pp2tran*TMath::Sin(phi2);

	ppz1=pp1tran*cotan1;
	ppz2=pp2tran*cotan2;

	pp1sq=TMath::Power(ppx1,2.)+TMath::Power(ppy1,2.)+TMath::Power(ppz1,2.);
	pp2sq=TMath::Power(ppx2,2.)+TMath::Power(ppy2,2.)+TMath::Power(ppz2,2.);
	pp1=TMath::Sqrt(pp1sq);
	pp2=TMath::Sqrt(pp2sq);
		
	Epp1=TMath::Sqrt(masschpion*masschpion+pp1sq);
	Epp2=TMath::Sqrt(masschpion*masschpion+pp2sq);

	// calculate more variables
	hatE1=E1/r1, hatE2=E2/r2, hatE3=E3/r3, hatx1=x1/r1, hatx2=x2/r2, hatx3=x3/r3, haty1=y1/r1, haty2=y2/r2, haty3=y3/r3, hatz1=z1/r1, hatz2=z2/r2, hatz3=z3/r3;
	

	// fill dgdeta array
	dg1deta[15]=-pp1tran*TMath::Power(pp1,2.)/Epp1, dg1deta[16]=pp1tran*pp1tran*cotan1/Epp1;
	dg1deta[18]=-pp2tran*TMath::Power(pp2,2.)/Epp2, dg1deta[19]=pp2tran*pp2tran*cotan2/Epp2;

	dg2deta[0]=hatx1, dg2deta[1]=hatE1*(TMath::Power(haty1,2)+TMath::Power(hatz1,2)), dg2deta[2]=-hatE1*hatx1*haty1, dg2deta[3]=-hatE1*hatz1*hatx1;
	dg2deta[5]=hatx2, dg2deta[6]=hatE2*(TMath::Power(haty2,2)+TMath::Power(hatz2,2)), dg2deta[7]=-hatE2*hatx2*haty2, dg2deta[8]=-hatE2*hatz2*hatx2;
	dg2deta[10]=hatx3, dg2deta[11]=hatE3*(TMath::Power(haty3,2)+TMath::Power(hatz3,2)), dg2deta[12]=-hatE3*hatx3*haty3, dg2deta[13]=-hatE3*hatz3*hatx3;
	dg2deta[15]=-TMath::Cos(phi1)*pp1tran*pp1tran, dg2deta[17]=-TMath::Sin(phi1)*pp1tran;
	dg2deta[18]=-TMath::Cos(phi2)*pp2tran*pp2tran, dg2deta[20]=-TMath::Sin(phi2)*pp2tran;

	dg3deta[0]=haty1, dg3deta[1]=dg2deta[2], dg3deta[2]=hatE1*(TMath::Power(hatx1,2)+TMath::Power(hatz1,2)), dg3deta[3]=-hatE1*hatz1*haty1;
	dg3deta[5]=haty2, dg3deta[6]=dg2deta[7], dg3deta[7]=hatE2*(TMath::Power(hatx2,2)+TMath::Power(hatz2,2)), dg3deta[8]=-hatE2*hatz2*haty2;
	dg3deta[10]=haty3, dg3deta[11]=dg2deta[12], dg3deta[12]=hatE3*(TMath::Power(hatx3,2)+TMath::Power(hatz3,2)), dg3deta[13]=-hatE3*hatz3*haty3;
	dg3deta[15]=-TMath::Sin(phi1)*pp1tran*pp1tran, dg3deta[17]=TMath::Cos(phi1)*pp1tran;
	dg3deta[18]=-TMath::Sin(phi2)*pp2tran*pp2tran, dg3deta[20]=TMath::Cos(phi2)*pp2tran;

	dg4deta[0]=hatz1, dg4deta[1]=dg2deta[3], dg4deta[2]=dg3deta[3], dg4deta[3]=hatE1*(TMath::Power(hatx1,2)+TMath::Power(haty1,2));
	dg4deta[5]=hatz2, dg4deta[6]=dg2deta[8], dg4deta[7]=dg3deta[8], dg4deta[8]=hatE2*(TMath::Power(hatx2,2)+TMath::Power(haty2,2));
	dg4deta[10]=hatz3, dg4deta[11]=dg2deta[13], dg4deta[12]=dg3deta[13], dg4deta[13]=hatE3*(TMath::Power(hatx3,2)+TMath::Power(haty3,2));
	dg4deta[15]=-cotan1*pp1tran*pp1tran, dg4deta[16]=pp1tran;
	dg4deta[18]=-cotan2*pp2tran*pp2tran, dg4deta[19]=pp2tran;

	dg5deta[1]=hatx1, dg5deta[2]=haty1, dg5deta[3]=hatz1;

	dg6deta[6]=hatx2, dg6deta[7]=haty2, dg6deta[8]=hatz2;

	dg7deta[11]=hatx3, dg7deta[12]=haty3, dg7deta[13]=hatz3; 
					

	// fill dgarray					
	dgarray[0]=dg1.Use(21,dg1deta), dgarray[1]=dg2.Use(21,dg2deta), dgarray[2]=dg3.Use(21,dg3deta), dgarray[3]=dg4.Use(21,dg4deta), dgarray[4]=dg5.Use(21,dg5deta), dgarray[5]=dg6.Use(21,dg6deta), dgarray[6]=dg7.Use(21,dg7deta);
					
	// fill G matrix 
	TMatrixDRow(matrix_temp,0)=dg1, TMatrixDRow(matrix_temp,1)=dg2, TMatrixDRow(matrix_temp,2)=dg3; TMatrixDRow(matrix_temp,3)=dg4, TMatrixDRow(matrix_temp,4)=dg5, TMatrixDRow(matrix_temp,5)=dg6, TMatrixDRow(matrix_temp,6)=dg7;
			

	return matrix_temp;
}

TMatrixD MyClass::Mtrans(TMatrixD ma) {
   TMatrixD ma_temp = ma;
   return ma_temp.T();
}

TMatrixD MyClass::MInvert(TMatrixD ma) {
   TMatrixD ma_temp = ma;
   return ma_temp.Invert();
}

TVectorD MyClass::Lambdavector(Int_t size, TMatrixD inveSmatrix, TMatrixD dgmatrix, TVectorD constr, TVectorD diffv) {
	TVectorD vector(size), rvector(size); //rvector.Print();
	rvector=constr+dgmatrix*diffv; //rvector.Print();
	vector=inveSmatrix*rvector;

	return vector;

}

TVectorD MyClass::Fillsigma2vectorkinfit(Int_t size, TMatrixD matrix, Int_t matrixcol, Int_t matrixrow) {
	TVectorD vector(size);
	
	for (Int_t i = 0; i < matrixrow; i++) {
		for (Int_t j = 0; j< matrixcol; j++) {	
			if (i==j) vector[i]=matrix[i][j];
		}
	}
	
	return vector;
}

TVectorD MyClass::Fillpullsvector(Int_t size, TVectorD sigma2vector_old, TVectorD sigma2vector_new, TVectorD inputvector_old, TVectorD inputvector_new) {
	Double_t Array[21] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
	TVectorD vector(size);
	
	for (Int_t i=0; i<size; i++) {
	  if((sigma2vector_old-sigma2vector_new)(i)<=0) printf("<=0!!!=%lf\n",(sigma2vector_old-sigma2vector_new)(i));
		Array[i]=((inputvector_old-inputvector_new)(i))/TMath::Sqrt((sigma2vector_old-sigma2vector_new)(i)); 
		//if (TMath::Abs(vector(i)) < 0.001) cout<<vector(i)<<endl;
		//vector(i)=(inputvector_old-inputvector_new)(i);
	}
	vector.Use(size,Array); 	
	return vector;
}

TVectorD MyClass::etakinfitfunc(TMatrixD Vmatrix, TMatrixD dgmatrixTrans, TVectorD lambdavector, TVectorD etatilde, Int_t rownb) {
	TVectorD vector(rownb);
	vector=etatilde-(Vmatrix*dgmatrixTrans)*lambdavector;
	return vector;
}

TVector2 MyClass::timinginfo(Int_t index, TLorentzVector trackmom) {
  //calculate the timing for electron and pion hypotheses for track with index index
  //assumes there is track to cluster
  //for each track need a pion and electron hypothesis
  Double_t betae, betap;
  Double_t  emass2=0.511*0.511;
  Double_t ppimod=trackmom.P();
  betae=ppimod/(sqrt(emass2+ppimod*ppimod));
  betap=ppimod/trackmom.E();
  Double_t te,tpi;
 
  //length of tracks, for pion/e hypothesis
  Double_t lenge, lengpi;
  //adding the three track lenghts: LH to FH, FH to DC wall, DC wall to IP
  lenge=len_seg[index][0][1]+len_seg[index][1][1]+len_seg[index][2][1];
  //adding 3 small lenght pieces from LH to cluster in calorimeter together
  Double_t callen;
  callen=leng_parts[index][0]+leng_parts[index][1]+leng_parts[index][2];
  //adding the three pieces to the track lenght
  lenge=lenge+callen;
  lengpi=len_seg[index][0][0]+len_seg[index][1][0]+len_seg[index][2][0];
  lengpi=lengpi+callen;

  te=(lenge)/(betae*speedc);
  tpi=(lengpi)/(betap*speedc);

  Double_t delte, deltp;
  delte=te-tcl[best_clu[index]-1];
  deltp=tpi-tcl[best_clu[index]-1];
  TVector2 reti(deltp, delte);
  return reti;

}

TLorentzVector MyClass::Getphoton4vector(Double_t E, Double_t x, Double_t y, Double_t z) {
	TLorentzVector tvector(0.,0.,0.,0.);
	Double_t px=0., py=0., pz=0.;
	Double_t rsq=0., r=0.;
	
	rsq=TMath::Power(x,2)+TMath::Power(y,2)+TMath::Power(z,2);	
	r=TMath::Sqrt(rsq);
	px=E*x/r, py=E*y/r, pz=E*z/r;
	
	tvector.SetPxPyPzE(px,py,pz,E);
	//printf("E=%lf,x=%lf,y=%lf,z=%lf,r=%lf\n",E,x,y,z,rsq);
	
	return tvector;
}

TLorentzVector MyClass::Gettrack4vectorkinfit(Double_t curv, Double_t cotan, Double_t phi) {
	TLorentzVector tvector(0.,0.,0.,0.);
	Double_t E=0., psq=0., ptran=0., px=0., py=0., pz=0.;
	
	ptran=1000.*1./TMath::Abs(curv);
	px=ptran*TMath::Cos(phi); py=ptran*TMath::Sin(phi), pz=ptran*cotan;
	psq=TMath::Power(ptran,2)+TMath::Power(pz,2);
	E=TMath::Sqrt(masschpion*masschpion+psq);
	//cout<<TMath::Abs(curv)<<endl;
	
	tvector.SetPxPyPzE(px,py,pz,E);
	
	return tvector;
}

TVectorD MyClass::Fillpermutvector(Int_t size, TVectorD input, Int_t index1, Int_t index2, Int_t index3) {
	TVectorD vector(size);
	TVectorD testvector(size);
	
	for (Int_t i=0;i<21;i++) {
		testvector(i)=i;
	}
	//input.Print();
	//index1=1, index2=0, index3=2; 
	//printf("%d,%d,%d \n",5*index1,5*index2,5*index3);
	//cout<<testvector(index1)<<endl;
	vector(0)=input(5*index1), vector(1)=input(5*index1+1), vector(2)=input(5*index1+2), vector(3)=input(5*index1+3), vector(4)=input(5*index1+4);
	vector(5)=input(5*index2), vector(6)=input(5*index2+1), vector(7)=input(5*index2+2), vector(8)=input(5*index2+3), vector(9)=input(5*index2+4);
	vector(10)=input(5*index3), vector(11)=input(5*index3+1), vector(12)=input(5*index3+2), vector(13)=input(5*index3+3), vector(14)=input(5*index3+4);
	
	vector(15)=input(15), vector(16)=input(16), vector(17)=input(17), vector(18)=input(18), vector(19)=input(19), vector(20)=input(20);
	
	//testvector.Print();
	//input.Print();
	//vector.Print();
	//printf("=========================\n");
	
	return vector;
}

Double_t MyClass::Chi2Eisrtest(TVectorD inputvector, TVectorD sigma2vector, Double_t isrenergy) {
	Double_t chi2isrE=0., isrEdiff=0., isrEdiff1=0.;
	
	isrEdiff=inputvector(0)-isrenergy;//362
	chi2isrE=TMath::Power(isrEdiff,2.)/sigma2vector(0);
	
	return chi2isrE;

}
