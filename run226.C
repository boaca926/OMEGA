#include <iostream>
void run226() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30674.root";
TString outputFileName = "output226.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
