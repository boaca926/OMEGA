#include <iostream>
void run54() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30435.root";
TString outputFileName = "output54.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
