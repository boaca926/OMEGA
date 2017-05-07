#include <iostream>
void run9() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30326.root";
TString outputFileName = "output9.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
