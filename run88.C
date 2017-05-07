#include <iostream>
void run88() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30493.root";
TString outputFileName = "output88.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
