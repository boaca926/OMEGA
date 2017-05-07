#include <iostream>
void run164() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30595.root";
TString outputFileName = "output164.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
