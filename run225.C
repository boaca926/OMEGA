#include <iostream>
void run225() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30673.root";
TString outputFileName = "output225.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
