#include <iostream>
void run101() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30515.root";
TString outputFileName = "output101.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
