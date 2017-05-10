#include <iostream>
void run286() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30761.root";
TString outputFileName = "output286.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
