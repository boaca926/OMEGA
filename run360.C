#include <iostream>
void run360() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30919.root";
TString outputFileName = "output360.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
