#include <iostream>
void run281() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30755.root";
TString outputFileName = "output281.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
