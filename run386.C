#include <iostream>
void run386() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30945.root";
TString outputFileName = "output386.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
