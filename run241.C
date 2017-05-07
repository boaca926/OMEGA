#include <iostream>
void run241() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30698.root";
TString outputFileName = "output241.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
