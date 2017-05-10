#include <iostream>
void run285() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30760.root";
TString outputFileName = "output285.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
