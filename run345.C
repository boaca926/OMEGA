#include <iostream>
void run345() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30901.root";
TString outputFileName = "output345.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
