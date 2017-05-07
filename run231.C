#include <iostream>
void run231() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30679.root";
TString outputFileName = "output231.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
