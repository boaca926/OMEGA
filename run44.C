#include <iostream>
void run44() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30399.root";
TString outputFileName = "output44.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
