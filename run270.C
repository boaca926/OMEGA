#include <iostream>
void run270() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30741.root";
TString outputFileName = "output270.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
