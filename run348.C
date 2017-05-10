#include <iostream>
void run348() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30905.root";
TString outputFileName = "output348.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
