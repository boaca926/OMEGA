#include <iostream>
void run403() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30974.root";
TString outputFileName = "output403.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
