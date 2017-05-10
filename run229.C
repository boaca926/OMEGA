#include <iostream>
void run229() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30677.root";
TString outputFileName = "output229.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
