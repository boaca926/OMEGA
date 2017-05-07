#include <iostream>
void run201() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30644.root";
TString outputFileName = "output201.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
