#include <iostream>
void run312() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30854.root";
TString outputFileName = "output312.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
