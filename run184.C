#include <iostream>
void run184() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30617.root";
TString outputFileName = "output184.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
