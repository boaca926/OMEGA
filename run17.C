#include <iostream>
void run17() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30345.root";
TString outputFileName = "output17.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
