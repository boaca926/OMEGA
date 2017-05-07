#include <iostream>
void run333() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30886.root";
TString outputFileName = "output333.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
