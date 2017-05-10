#include <iostream>
void run323() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30869.root";
TString outputFileName = "output323.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
