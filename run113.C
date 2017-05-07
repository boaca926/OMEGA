#include <iostream>
void run113() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30537.root";
TString outputFileName = "output113.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
