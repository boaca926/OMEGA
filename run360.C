#include <iostream>
void run360() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30919.root";
TString outputFileName = "output360.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
