#include <iostream>
void run306() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30786.root";
TString outputFileName = "output306.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
