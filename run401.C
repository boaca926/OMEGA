#include <iostream>
void run401() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30972.root";
TString outputFileName = "output401.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
