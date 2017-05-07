#include <iostream>
void run161() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30592.root";
TString outputFileName = "output161.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
