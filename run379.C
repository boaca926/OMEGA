#include <iostream>
void run379() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30938.root";
TString outputFileName = "output379.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
