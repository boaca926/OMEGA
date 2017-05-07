#include <iostream>
void run133() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30560.root";
TString outputFileName = "output133.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
