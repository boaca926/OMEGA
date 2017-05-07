#include <iostream>
void run186() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30619.root";
TString outputFileName = "output186.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
