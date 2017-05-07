#include <iostream>
void run190() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30623.root";
TString outputFileName = "output190.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
