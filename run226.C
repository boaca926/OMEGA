#include <iostream>
void run226() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30674.root";
TString outputFileName = "output226.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
