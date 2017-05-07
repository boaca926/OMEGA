#include <iostream>
void run80() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30485.root";
TString outputFileName = "output80.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
