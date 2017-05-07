#include <iostream>
void run142() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30569.root";
TString outputFileName = "output142.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
