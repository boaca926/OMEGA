#include <iostream>
void run15() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30343.root";
TString outputFileName = "output15.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
