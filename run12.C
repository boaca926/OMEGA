#include <iostream>
void run12() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30340.root";
TString outputFileName = "output12.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
