#include <iostream>
void run323() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30869.root";
TString outputFileName = "output323.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
