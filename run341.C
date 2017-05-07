#include <iostream>
void run341() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30897.root";
TString outputFileName = "output341.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
