#include <iostream>
void run212() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30656.root";
TString outputFileName = "output212.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
