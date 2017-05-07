#include <iostream>
void run160() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30590.root";
TString outputFileName = "output160.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
