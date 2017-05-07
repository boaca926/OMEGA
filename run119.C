#include <iostream>
void run119() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30544.root";
TString outputFileName = "output119.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
