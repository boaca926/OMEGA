#include <iostream>
void run380() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30939.root";
TString outputFileName = "output380.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
