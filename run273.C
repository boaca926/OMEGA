#include <iostream>
void run273() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30744.root";
TString outputFileName = "output273.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
