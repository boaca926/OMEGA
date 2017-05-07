#include <iostream>
void run178() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30609.root";
TString outputFileName = "output178.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
