#include <iostream>
void run415() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30987.root";
TString outputFileName = "output415.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
