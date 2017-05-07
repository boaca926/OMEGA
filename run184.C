#include <iostream>
void run184() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30617.root";
TString outputFileName = "output184.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
