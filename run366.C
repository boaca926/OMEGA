#include <iostream>
void run366() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30925.root";
TString outputFileName = "output366.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
