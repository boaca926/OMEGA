#include <iostream>
void run26() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30374.root";
TString outputFileName = "output26.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
