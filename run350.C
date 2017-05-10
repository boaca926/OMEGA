#include <iostream>
void run350() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30907.root";
TString outputFileName = "output350.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
