#include <iostream>
void run21() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30359.root";
TString outputFileName = "output21.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
