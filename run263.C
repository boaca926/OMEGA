#include <iostream>
void run263() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30733.root";
TString outputFileName = "output263.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
