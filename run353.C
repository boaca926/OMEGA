#include <iostream>
void run353() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30910.root";
TString outputFileName = "output353.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
