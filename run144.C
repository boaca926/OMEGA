#include <iostream>
void run144() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30571.root";
TString outputFileName = "output144.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
