#include <iostream>
void run117() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30541.root";
TString outputFileName = "output117.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
