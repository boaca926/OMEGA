#include <iostream>
void run402() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30973.root";
TString outputFileName = "output402.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
