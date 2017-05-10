#include <iostream>
void run201() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30644.root";
TString outputFileName = "output201.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
