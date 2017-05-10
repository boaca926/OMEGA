#include <iostream>
void run262() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30732.root";
TString outputFileName = "output262.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
