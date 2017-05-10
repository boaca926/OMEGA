#include <iostream>
void run213() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30657.root";
TString outputFileName = "output213.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
