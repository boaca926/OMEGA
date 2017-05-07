#include <iostream>
void run200() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30635.root";
TString outputFileName = "output200.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
