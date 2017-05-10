#include <iostream>
void run283() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30757.root";
TString outputFileName = "output283.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
