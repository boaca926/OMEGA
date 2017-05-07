#include <iostream>
void run124() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30549.root";
TString outputFileName = "output124.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
