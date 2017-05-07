#include <iostream>
void run57() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30439.root";
TString outputFileName = "output57.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
