#include <iostream>
void run258() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30724.root";
TString outputFileName = "output258.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
