#include <iostream>
void run209() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30653.root";
TString outputFileName = "output209.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
