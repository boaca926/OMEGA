#include <iostream>
void run241() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30698.root";
TString outputFileName = "output241.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
