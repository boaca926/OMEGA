#include <iostream>
void run168() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30599.root";
TString outputFileName = "output168.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
