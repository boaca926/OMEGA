#include <iostream>
void run330() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30883.root";
TString outputFileName = "output330.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
