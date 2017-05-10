#include <iostream>
void run260() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30728.root";
TString outputFileName = "output260.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
