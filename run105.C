#include <iostream>
void run105() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30519.root";
TString outputFileName = "output105.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
