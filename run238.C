#include <iostream>
void run238() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30695.root";
TString outputFileName = "output238.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
