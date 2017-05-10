#include <iostream>
void run380() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30939.root";
TString outputFileName = "output380.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
