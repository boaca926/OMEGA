#include <iostream>
void run125() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30550.root";
TString outputFileName = "output125.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
