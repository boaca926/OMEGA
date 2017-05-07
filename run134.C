#include <iostream>
void run134() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30561.root";
TString outputFileName = "output134.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
