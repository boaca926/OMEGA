#include <iostream>
void run405() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30976.root";
TString outputFileName = "output405.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
