#include <iostream>
void run264() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30734.root";
TString outputFileName = "output264.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
