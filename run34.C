#include <iostream>
void run34() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30382.root";
TString outputFileName = "output34.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
