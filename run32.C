#include <iostream>
void run32() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30380.root";
TString outputFileName = "output32.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
