#include <iostream>
void run234() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30682.root";
TString outputFileName = "output234.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
