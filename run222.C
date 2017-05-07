#include <iostream>
void run222() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30669.root";
TString outputFileName = "output222.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
