#include <iostream>
void run90() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30496.root";
TString outputFileName = "output90.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
