#include <iostream>
void run286() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30761.root";
TString outputFileName = "output286.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
