#include <iostream>
void run389() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30949.root";
TString outputFileName = "output389.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
