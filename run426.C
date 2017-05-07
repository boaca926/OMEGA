#include <iostream>
void run426() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30998.root";
TString outputFileName = "output426.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
