#include <iostream>
void run357() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30915.root";
TString outputFileName = "output357.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
