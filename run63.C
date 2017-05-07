#include <iostream>
void run63() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30451.root";
TString outputFileName = "output63.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
