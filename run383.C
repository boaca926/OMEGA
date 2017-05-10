#include <iostream>
void run383() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30942.root";
TString outputFileName = "output383.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
