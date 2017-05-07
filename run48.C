#include <iostream>
void run48() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30403.root";
TString outputFileName = "output48.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
