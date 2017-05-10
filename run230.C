#include <iostream>
void run230() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30678.root";
TString outputFileName = "output230.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
