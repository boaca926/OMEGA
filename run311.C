#include <iostream>
void run311() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30853.root";
TString outputFileName = "output311.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
