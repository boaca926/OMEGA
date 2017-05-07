#include <iostream>
void run122() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30547.root";
TString outputFileName = "output122.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
