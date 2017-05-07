#include <iostream>
void run400() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30971.root";
TString outputFileName = "output400.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
