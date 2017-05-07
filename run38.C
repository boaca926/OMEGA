#include <iostream>
void run38() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30387.root";
TString outputFileName = "output38.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
