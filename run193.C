#include <iostream>
void run193() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30626.root";
TString outputFileName = "output193.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
