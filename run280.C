#include <iostream>
void run280() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30754.root";
TString outputFileName = "output280.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
