#include <iostream>
void run342() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30898.root";
TString outputFileName = "output342.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
