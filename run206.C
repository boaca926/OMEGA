#include <iostream>
void run206() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30649.root";
TString outputFileName = "output206.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
