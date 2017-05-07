#include <iostream>
void run165() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30596.root";
TString outputFileName = "output165.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
