#include <iostream>
void run30() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30378.root";
TString outputFileName = "output30.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
