#include <iostream>
void run306() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30786.root";
TString outputFileName = "output306.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
