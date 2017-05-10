#include <iostream>
void run415() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30987.root";
TString outputFileName = "output415.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
