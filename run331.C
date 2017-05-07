#include <iostream>
void run331() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30884.root";
TString outputFileName = "output331.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
