#include <iostream>
void run43() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30397.root";
TString outputFileName = "output43.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
