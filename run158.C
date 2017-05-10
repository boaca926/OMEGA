#include <iostream>
void run158() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30588.root";
TString outputFileName = "output158.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
