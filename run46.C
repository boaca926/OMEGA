#include <iostream>
void run46() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30401.root";
TString outputFileName = "output46.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
