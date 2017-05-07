#include <iostream>
void run279() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30753.root";
TString outputFileName = "output279.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
