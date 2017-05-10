#include <iostream>
void run352() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30909.root";
TString outputFileName = "output352.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
