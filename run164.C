#include <iostream>
void run164() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30595.root";
TString outputFileName = "output164.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
