#include <iostream>
void run123() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30548.root";
TString outputFileName = "output123.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
