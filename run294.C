#include <iostream>
void run294() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30773.root";
TString outputFileName = "output294.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
