#include <iostream>
void run136() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30563.root";
TString outputFileName = "output136.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
