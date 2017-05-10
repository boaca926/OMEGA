#include <iostream>
void run174() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30605.root";
TString outputFileName = "output174.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
