#include <iostream>
void run368() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30927.root";
TString outputFileName = "output368.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
