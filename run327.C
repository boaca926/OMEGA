#include <iostream>
void run327() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30874.root";
TString outputFileName = "output327.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
