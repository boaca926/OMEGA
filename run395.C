#include <iostream>
void run395() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30958.root";
TString outputFileName = "output395.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
