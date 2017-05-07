#include <iostream>
void run237() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30685.root";
TString outputFileName = "output237.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
