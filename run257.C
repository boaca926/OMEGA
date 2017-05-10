#include <iostream>
void run257() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30723.root";
TString outputFileName = "output257.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
