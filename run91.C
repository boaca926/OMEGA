#include <iostream>
void run91() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30501.root";
TString outputFileName = "output91.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
