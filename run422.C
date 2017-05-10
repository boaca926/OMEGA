#include <iostream>
void run422() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30994.root";
TString outputFileName = "output422.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
