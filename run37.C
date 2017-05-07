#include <iostream>
void run37() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30386.root";
TString outputFileName = "output37.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
