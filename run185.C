#include <iostream>
void run185() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30618.root";
TString outputFileName = "output185.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
