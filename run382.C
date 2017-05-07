#include <iostream>
void run382() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30941.root";
TString outputFileName = "output382.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
