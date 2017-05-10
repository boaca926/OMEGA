#include <iostream>
void run280() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30754.root";
TString outputFileName = "output280.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
