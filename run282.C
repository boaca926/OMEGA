#include <iostream>
void run282() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30756.root";
TString outputFileName = "output282.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
