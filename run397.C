#include <iostream>
void run397() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30960.root";
TString outputFileName = "output397.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
