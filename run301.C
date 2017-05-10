#include <iostream>
void run301() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30781.root";
TString outputFileName = "output301.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
