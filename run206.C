#include <iostream>
void run206() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30649.root";
TString outputFileName = "output206.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
