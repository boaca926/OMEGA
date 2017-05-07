#include <iostream>
void run11() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30339.root";
TString outputFileName = "output11.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
