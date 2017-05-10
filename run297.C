#include <iostream>
void run297() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30777.root";
TString outputFileName = "output297.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
