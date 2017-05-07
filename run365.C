#include <iostream>
void run365() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30924.root";
TString outputFileName = "output365.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
