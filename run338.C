#include <iostream>
void run338() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30894.root";
TString outputFileName = "output338.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
