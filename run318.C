#include <iostream>
void run318() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30861.root";
TString outputFileName = "output318.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
