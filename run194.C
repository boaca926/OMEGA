#include <iostream>
void run194() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30627.root";
TString outputFileName = "output194.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
