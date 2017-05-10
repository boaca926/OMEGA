#include <iostream>
void run209() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30653.root";
TString outputFileName = "output209.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
