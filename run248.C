#include <iostream>
void run248() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30709.root";
TString outputFileName = "output248.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
