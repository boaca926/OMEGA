#include <iostream>
void run23() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30371.root";
TString outputFileName = "output23.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
