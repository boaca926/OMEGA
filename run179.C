#include <iostream>
void run179() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30610.root";
TString outputFileName = "output179.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
