#include <iostream>
void run170() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30601.root";
TString outputFileName = "output170.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
