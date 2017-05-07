#include <iostream>
void run145() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30572.root";
TString outputFileName = "output145.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
