#include <iostream>
void run292() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30771.root";
TString outputFileName = "output292.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
