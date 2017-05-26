#include "Getname.C"
#include <iostream>
#include <string>
#include "gethisto.C"
#include "myfunc.C"

const double ERRORLIMIT = 1E-3;

double w0(double *y, double *par){ 
	double m = par[0]; //std::cout<<"m = "<<m<<endl;
	//double L = 2*TMath::Log(sqrtS/me); //std::cout<<"L = "<<L<<endl;
	double x = 1-TMath::Power(par[0]/sqrtS,2); //std::cout<<"x = "<<x<<endl;
	double c = TMath::Power(2*me/sqrtS,2); //std::cout<<"c = "<<c<<endl;
	double p1 = 1/x-1+x/2;
	double p2 = x/2;
	double p3 = 1/x-2;
	double p4 = x;
	double F1 = p1-p2-c*p3;
	double F2 = c*p3+2*p2-p1;
	double yy=y[0];
	double f = F1+F2*TMath::Power(y[0],2);
	//cout<<par[0]<<endl;
	
	return f;
}

double W0(double *y) {

}

double getW0(double alphapi, double x, double theta0) {
	double W0_temp = 0.;
	double costheta = TMath::Cos(theta0);
	double P1 = 0.;
	double P2 =0.;
	P1 = 2-2*x+x*x;
	P2 = x*x;
	
	W0_temp = alphapi*(P1*TMath::Log((1+costheta)/(1-costheta))-P2*costheta)/x;	
			
	return W0_temp;
}


double getSigma(double sqrtS, double m, double W0, double sigma0) {
	double sigma_temp = 0.;
	double S = TMath::Power(sqrtS,2);
 
 	sigma_temp=(2*m/S)*W0*(sqrtS-m)*sigma0;
	return sigma_temp;
}

void omegacross() {
	// define constants
	
	
	
	const double sigma0 = 300; // born cross section of e+e->omega in nano bar, mu = 10^-6, femto = 10^-5, nano =10^-9
	// define variables
	double x=0.; // effective fraction
	double W0=0.; // radiative function
	double sigma=0.; // visible cross section
	// get values
	x = 1-TMath::Power(m_omega/sqrtS,2);
	W0 = getW0(alphapi,x,theta0);
	sigma=getSigma(sqrtS,m_omega,W0,sigma0);
	// integrate
	// initialize function to be intergrated
	const int nb = 1;
	double parnb[nb] = {20.};
	double y1=1, y2=2;	
	double W0 = 0;
	TF1 *f1 = new TF1("fBW",w0,y1, y2,nb);
	for (int i=0;i<nb;i++) {
		f1->SetParameter(0,parnb[i]);
		f1->SetParNames("Norm");
		f1->Draw();		 
   	W0 = fBW->Integral(y1,y2);
   	std::cout << s2 << std::endl;
   }	
 
   
	
	
	std::cout<<"omega mass = "<<m_omega<<endl;
	std::cout<<"center-of-mass energy = "<<sqrtS<<endl;
	std::cout<<"effective fraction = "<<x<<endl;
	std::cout<<"polar angle = "<<theta0<<endl;
	std::cout<<"radiative function W0 = "<<W0<<endl;
	std::cout<<"born cross section sigma0 = "<<sigma0<<endl;
	std::cout<<"visible cross section of omega "<<sigma<<" at C.o.M energy = "<<sqrtS<<endl;



}
