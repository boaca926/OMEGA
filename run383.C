#include <iostream>
void run383() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30942.root";
TString outputFileName = "output383.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
