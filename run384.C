#include <iostream>
void run384() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30943.root";
TString outputFileName = "output384.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
