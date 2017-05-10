#include <iostream>
void run190() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30623.root";
TString outputFileName = "output190.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
