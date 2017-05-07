#include <iostream>
void run39() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30388.root";
TString outputFileName = "output39.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
