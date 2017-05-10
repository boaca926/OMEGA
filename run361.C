#include <iostream>
void run361() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30920.root";
TString outputFileName = "output361.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
