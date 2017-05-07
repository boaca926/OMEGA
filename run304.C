#include <iostream>
void run304() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30784.root";
TString outputFileName = "output304.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
