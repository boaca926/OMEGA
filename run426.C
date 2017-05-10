#include <iostream>
void run426() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30998.root";
TString outputFileName = "output426.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
