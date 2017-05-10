#include <iostream>
void run236() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30684.root";
TString outputFileName = "output236.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
