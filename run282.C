#include <iostream>
void run282() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30756.root";
TString outputFileName = "output282.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
