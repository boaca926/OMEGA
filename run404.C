#include <iostream>
void run404() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30975.root";
TString outputFileName = "output404.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
