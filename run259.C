#include <iostream>
void run259() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30725.root";
TString outputFileName = "output259.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
