#include <iostream>
void run237() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30685.root";
TString outputFileName = "output237.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
