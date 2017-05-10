#include <iostream>
void run368() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30927.root";
TString outputFileName = "output368.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
