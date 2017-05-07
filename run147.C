#include <iostream>
void run147() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30574.root";
TString outputFileName = "output147.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
