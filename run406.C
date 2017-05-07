#include <iostream>
void run406() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30977.root";
TString outputFileName = "output406.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
