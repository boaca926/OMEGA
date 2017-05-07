#include <iostream>
void run260() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30728.root";
TString outputFileName = "output260.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
