#include <iostream>
void run224() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30671.root";
TString outputFileName = "output224.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
