#include <iostream>
void run16() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30344.root";
TString outputFileName = "output16.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
