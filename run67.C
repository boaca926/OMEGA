#include <iostream>
void run67() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30459.root";
TString outputFileName = "output67.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
