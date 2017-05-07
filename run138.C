#include <iostream>
void run138() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30565.root";
TString outputFileName = "output138.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
