#include <iostream>
void run217() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30663.root";
TString outputFileName = "output217.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
