#include <iostream>
void run186() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30619.root";
TString outputFileName = "output186.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
