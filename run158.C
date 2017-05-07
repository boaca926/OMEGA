#include <iostream>
void run158() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30588.root";
TString outputFileName = "output158.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
