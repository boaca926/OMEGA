#include <iostream>
void run33() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30381.root";
TString outputFileName = "output33.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
