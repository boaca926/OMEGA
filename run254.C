#include <iostream>
void run254() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30719.root";
TString outputFileName = "output254.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
