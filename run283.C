#include <iostream>
void run283() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30757.root";
TString outputFileName = "output283.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
