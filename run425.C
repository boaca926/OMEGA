#include <iostream>
void run425() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30997.root";
TString outputFileName = "output425.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
