#include <iostream>
void run402() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30973.root";
TString outputFileName = "output402.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
