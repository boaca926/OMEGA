#include <iostream>
void run131() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30556.root";
TString outputFileName = "output131.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
