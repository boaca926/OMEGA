#include <iostream>
void run403() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30974.root";
TString outputFileName = "output403.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
