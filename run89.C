#include <iostream>
void run89() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30494.root";
TString outputFileName = "output89.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
