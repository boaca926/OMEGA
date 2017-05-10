#include <iostream>
void run242() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30699.root";
TString outputFileName = "output242.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
