#include <iostream>
void run330() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30883.root";
TString outputFileName = "output330.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
