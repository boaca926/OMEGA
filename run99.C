#include <iostream>
void run99() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30510.root";
TString outputFileName = "output99.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
