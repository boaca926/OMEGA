#include <iostream>
void run25() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30373.root";
TString outputFileName = "output25.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
