#include <iostream>
void run336() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30889.root";
TString outputFileName = "output336.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
