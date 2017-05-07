#include <iostream>
void run52() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30420.root";
TString outputFileName = "output52.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
