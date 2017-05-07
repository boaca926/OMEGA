#include <iostream>
void run204() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30647.root";
TString outputFileName = "output204.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
