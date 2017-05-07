#include <iostream>
void run172() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30603.root";
TString outputFileName = "output172.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
