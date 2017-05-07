#include <iostream>
void run329() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30882.root";
TString outputFileName = "output329.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
