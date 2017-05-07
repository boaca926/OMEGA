#include <iostream>
void run230() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30678.root";
TString outputFileName = "output230.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
