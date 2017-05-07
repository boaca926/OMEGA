#include <iostream>
void run68() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30462.root";
TString outputFileName = "output68.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
