#include <iostream>
void run246() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30706.root";
TString outputFileName = "output246.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
