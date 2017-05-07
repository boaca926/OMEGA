#include <iostream>
void run385() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30944.root";
TString outputFileName = "output385.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
