#include <iostream>
void run165() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30596.root";
TString outputFileName = "output165.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
