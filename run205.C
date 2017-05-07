#include <iostream>
void run205() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30648.root";
TString outputFileName = "output205.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
