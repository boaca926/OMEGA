#include <iostream>
void run318() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30861.root";
TString outputFileName = "output318.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
