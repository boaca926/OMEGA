#include <iostream>
void run74() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30468.root";
TString outputFileName = "output74.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
