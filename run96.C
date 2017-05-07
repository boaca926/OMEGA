#include <iostream>
void run96() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30507.root";
TString outputFileName = "output96.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
