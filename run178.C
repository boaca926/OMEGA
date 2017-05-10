#include <iostream>
void run178() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30609.root";
TString outputFileName = "output178.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
