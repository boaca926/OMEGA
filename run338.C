#include <iostream>
void run338() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30894.root";
TString outputFileName = "output338.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
