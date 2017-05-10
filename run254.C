#include <iostream>
void run254() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30719.root";
TString outputFileName = "output254.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
