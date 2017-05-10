#include <iostream>
void run231() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30679.root";
TString outputFileName = "output231.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
