#include <iostream>
void run375() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30934.root";
TString outputFileName = "output375.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
