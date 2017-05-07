#include <iostream>
void run58() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30440.root";
TString outputFileName = "output58.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
