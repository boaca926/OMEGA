#include <iostream>
void run249() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30710.root";
TString outputFileName = "output249.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
