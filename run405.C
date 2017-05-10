#include <iostream>
void run405() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30976.root";
TString outputFileName = "output405.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
