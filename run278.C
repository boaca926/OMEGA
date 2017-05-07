#include <iostream>
void run278() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30752.root";
TString outputFileName = "output278.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
