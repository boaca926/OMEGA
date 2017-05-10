#include <iostream>
void run384() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30943.root";
TString outputFileName = "output384.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
