#include <iostream>
void run59() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30441.root";
TString outputFileName = "output59.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
