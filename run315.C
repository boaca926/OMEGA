#include <iostream>
void run315() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30858.root";
TString outputFileName = "output315.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
