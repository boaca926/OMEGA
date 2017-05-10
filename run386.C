#include <iostream>
void run386() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30945.root";
TString outputFileName = "output386.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
