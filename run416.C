#include <iostream>
void run416() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30988.root";
TString outputFileName = "output416.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
