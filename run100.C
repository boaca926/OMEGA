#include <iostream>
void run100() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30511.root";
TString outputFileName = "output100.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
