#include <iostream>
void run314() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30857.root";
TString outputFileName = "output314.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
