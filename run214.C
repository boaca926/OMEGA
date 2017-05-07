#include <iostream>
void run214() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30658.root";
TString outputFileName = "output214.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
