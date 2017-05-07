#include <iostream>
void run69() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30463.root";
TString outputFileName = "output69.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
