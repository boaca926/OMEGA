#include <iostream>
void run102() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30516.root";
TString outputFileName = "output102.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
