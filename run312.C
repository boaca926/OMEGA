#include <iostream>
void run312() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30854.root";
TString outputFileName = "output312.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
