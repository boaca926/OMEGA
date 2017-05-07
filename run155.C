#include <iostream>
void run155() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30585.root";
TString outputFileName = "output155.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
