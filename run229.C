#include <iostream>
void run229() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30677.root";
TString outputFileName = "output229.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
