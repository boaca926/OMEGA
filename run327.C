#include <iostream>
void run327() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30874.root";
TString outputFileName = "output327.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
