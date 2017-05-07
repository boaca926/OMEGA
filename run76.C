#include <iostream>
void run76() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30470.root";
TString outputFileName = "output76.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
