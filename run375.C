#include <iostream>
void run375() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30934.root";
TString outputFileName = "output375.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
