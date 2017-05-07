#include <iostream>
void run308() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30788.root";
TString outputFileName = "output308.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
