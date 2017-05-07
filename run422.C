#include <iostream>
void run422() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30994.root";
TString outputFileName = "output422.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
