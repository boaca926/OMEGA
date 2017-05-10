#include <iostream>
void run299() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30779.root";
TString outputFileName = "output299.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
