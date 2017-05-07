#include <iostream>
void run275() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30746.root";
TString outputFileName = "output275.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
