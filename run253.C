#include <iostream>
void run253() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30717.root";
TString outputFileName = "output253.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
