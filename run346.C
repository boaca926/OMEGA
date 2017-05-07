#include <iostream>
void run346() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30902.root";
TString outputFileName = "output346.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
