#include <iostream>
void run425() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30997.root";
TString outputFileName = "output425.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
