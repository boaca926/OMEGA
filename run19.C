#include <iostream>
void run19() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30348.root";
TString outputFileName = "output19.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
