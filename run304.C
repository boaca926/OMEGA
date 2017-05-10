#include <iostream>
void run304() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30784.root";
TString outputFileName = "output304.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
