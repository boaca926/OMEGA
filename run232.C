#include <iostream>
void run232() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30680.root";
TString outputFileName = "output232.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
