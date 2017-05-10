#include <iostream>
void run243() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30703.root";
TString outputFileName = "output243.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
