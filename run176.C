#include <iostream>
void run176() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30607.root";
TString outputFileName = "output176.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
