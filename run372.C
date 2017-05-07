#include <iostream>
void run372() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30931.root";
TString outputFileName = "output372.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
