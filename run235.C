#include <iostream>
void run235() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30683.root";
TString outputFileName = "output235.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
