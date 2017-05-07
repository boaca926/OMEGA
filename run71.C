#include <iostream>
void run71() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30465.root";
TString outputFileName = "output71.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
