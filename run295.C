#include <iostream>
void run295() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30775.root";
TString outputFileName = "output295.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
