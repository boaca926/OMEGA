#include <iostream>
void run397() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30960.root";
TString outputFileName = "output397.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
