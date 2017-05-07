#include <iostream>
void run129() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30554.root";
TString outputFileName = "output129.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
