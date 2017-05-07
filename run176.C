#include <iostream>
void run176() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30607.root";
TString outputFileName = "output176.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
