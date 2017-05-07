#include <iostream>
void run13() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30341.root";
TString outputFileName = "output13.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
