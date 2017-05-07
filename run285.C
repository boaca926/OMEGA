#include <iostream>
void run285() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30760.root";
TString outputFileName = "output285.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
