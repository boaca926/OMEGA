#include <iostream>
void run203() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30646.root";
TString outputFileName = "output203.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
