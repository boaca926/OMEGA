#include <iostream>
void run341() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30897.root";
TString outputFileName = "output341.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
