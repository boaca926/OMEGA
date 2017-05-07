#include <iostream>
void run170() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30601.root";
TString outputFileName = "output170.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
