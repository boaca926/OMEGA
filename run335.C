#include <iostream>
void run335() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30888.root";
TString outputFileName = "output335.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
