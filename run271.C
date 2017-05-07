#include <iostream>
void run271() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30742.root";
TString outputFileName = "output271.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
