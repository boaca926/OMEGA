#include <iostream>
void run240() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30697.root";
TString outputFileName = "output240.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
