#include <iostream>
void run169() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30600.root";
TString outputFileName = "output169.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
