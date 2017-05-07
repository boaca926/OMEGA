#include <iostream>
void run146() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30573.root";
TString outputFileName = "output146.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
