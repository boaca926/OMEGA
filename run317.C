#include <iostream>
void run317() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30860.root";
TString outputFileName = "output317.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
