#include <iostream>
void run269() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30740.root";
TString outputFileName = "output269.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
