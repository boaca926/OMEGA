//+ Example on the  usage of the adaptive 1D integration algorithm of MathMore  
// it calculates the numerically cumulative integral of a distribution (like in this case the BreitWigner) 
// to execute the macro type it (you need to compile with AClic)
//
// root[0]: .x mathmoreIntegration.C+ 
//
// This tutorials require having libMathMore built with ROOT. 
// 
// To build mathmore you need to have a version of GSL >= 1.8 installed in your system
// The ROOT configure will automatically find GSL if the script gsl-config (from GSL) is in your PATH,. 
// otherwise you need to configure root with the options --gsl-incdir and --gsl-libdir. 
//
//
// Authors: M. Slawinska and L. Moneta

#include "TMath.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TLegend.h"

//#include "TLabel.h"
#include "Math/Functor.h"
#include "Math/WrappedFunction.h"
#include "Math/IFunction.h"
#include "Math/Integrator.h"
#include <iostream>

#include "TStopwatch.h"
#include "TF1.h"

#include <limits>

//!calculates exact integral of Breit Wigner distribution
//!and compares with existing methods

int nc = 0; 
double exactIntegral( double a, double b) {
   
  return (TMath::ATan(2*b)- TMath::ATan(2*a))/ TMath::Pi(); 
}
double func( double x){ 
   nc++;
   return TMath::BreitWigner(x);
}
// TF1 requires the function to have the ( )( double *, double *) signature 
double func2(const double *x, const double * = 0){ 
   nc++;
   return x[0]*x[0];
}




void  testIntegPerf(double x1, double x2, int n = 100000){


   std::cout << "\n\n***************************************************************\n";
   std::cout << "Test integration performances in interval [ " << x1 << " , " << x2 << " ]\n\n";
  
  TStopwatch timer; 

  double dx = (x2-x1)/double(n); 



  //TF1 *fBW = new TF1("fBW","TMath::BreitWigner(x)",x1, x2);  //  this is faster but cannot measure number of function calls
  TF1 *fBW = new TF1("fBW",func2,x1, x2,0);
 
  nc = 0; 
  double s2 = 0; 
  s2 = fBW->Integral(x1,x2);
 
  std::cout << s2 << std::endl;  


}



void myfunc(double y1, double y2)
{
#if defined(__CINT__) && !defined(__MAKECINT__) 
  cout << "WARNING: This tutorial can run only using ACliC, you must run it by doing: " << endl;
  cout << "\t .x $ROOTSYS/tutorials/math/mathmoreIntegration.C+" << endl; 
  return;
#endif
	double y1 =1, y2 = 2;
   testIntegPerf(y1, y2);
}

