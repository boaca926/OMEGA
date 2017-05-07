#include <iostream>
void run381() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30940.root";
TString outputFileName = "output381.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
