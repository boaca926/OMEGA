#include <iostream>
void run372() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30931.root";
TString outputFileName = "output372.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
