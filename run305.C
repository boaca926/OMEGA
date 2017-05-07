#include <iostream>
void run305() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30785.root";
TString outputFileName = "output305.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
