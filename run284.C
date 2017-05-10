#include <iostream>
void run284() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30759.root";
TString outputFileName = "output284.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
