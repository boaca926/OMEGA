#include <iostream>
void run10() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30338.root";
TString outputFileName = "output10.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
