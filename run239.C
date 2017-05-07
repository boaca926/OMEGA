#include <iostream>
void run239() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30696.root";
TString outputFileName = "output239.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
