#include <iostream>
void run78() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30472.root";
TString outputFileName = "output78.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
