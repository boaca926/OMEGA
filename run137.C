#include <iostream>
void run137() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30564.root";
TString outputFileName = "output137.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
