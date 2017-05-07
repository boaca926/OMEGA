#include <iostream>
void run235() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30683.root";
TString outputFileName = "output235.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
