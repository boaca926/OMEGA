#include <iostream>
void run208() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30652.root";
TString outputFileName = "output208.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
