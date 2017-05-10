#include <iostream>
void run329() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30882.root";
TString outputFileName = "output329.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
