#include <iostream>
void run367() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30926.root";
TString outputFileName = "output367.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
