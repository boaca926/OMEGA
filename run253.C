#include <iostream>
void run253() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30717.root";
TString outputFileName = "output253.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
