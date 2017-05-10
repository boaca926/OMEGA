#include <iostream>
void run263() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30733.root";
TString outputFileName = "output263.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
