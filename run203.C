#include <iostream>
void run203() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30646.root";
TString outputFileName = "output203.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
