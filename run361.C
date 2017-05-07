#include <iostream>
void run361() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30920.root";
TString outputFileName = "output361.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
