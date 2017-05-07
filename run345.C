#include <iostream>
void run345() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30901.root";
TString outputFileName = "output345.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
