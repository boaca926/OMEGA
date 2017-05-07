#include <iostream>
void run242() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30699.root";
TString outputFileName = "output242.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
