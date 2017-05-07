#include <iostream>
void run166() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30597.root";
TString outputFileName = "output166.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
