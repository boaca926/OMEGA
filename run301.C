#include <iostream>
void run301() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30781.root";
TString outputFileName = "output301.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
