#include <iostream>
void run355() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30912.root";
TString outputFileName = "output355.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
