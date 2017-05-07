#include <iostream>
void run218() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30664.root";
TString outputFileName = "output218.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
