#include <iostream>
void run188() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30621.root";
TString outputFileName = "output188.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
