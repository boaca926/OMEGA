#include <iostream>
void run307() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30787.root";
TString outputFileName = "output307.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
