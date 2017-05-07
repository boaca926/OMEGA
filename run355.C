#include <iostream>
void run355() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30912.root";
TString outputFileName = "output355.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
