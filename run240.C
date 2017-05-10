#include <iostream>
void run240() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30697.root";
TString outputFileName = "output240.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
