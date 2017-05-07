#include <iostream>
void run374() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30933.root";
TString outputFileName = "output374.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
