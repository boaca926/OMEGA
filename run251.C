#include <iostream>
void run251() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30712.root";
TString outputFileName = "output251.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
