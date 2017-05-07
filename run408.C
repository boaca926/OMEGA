#include <iostream>
void run408() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30979.root";
TString outputFileName = "output408.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
