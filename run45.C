#include <iostream>
void run45() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30400.root";
TString outputFileName = "output45.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
