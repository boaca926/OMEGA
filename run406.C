#include <iostream>
void run406() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30977.root";
TString outputFileName = "output406.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
