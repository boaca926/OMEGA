#include <iostream>
void run300() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30780.root";
TString outputFileName = "output300.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
