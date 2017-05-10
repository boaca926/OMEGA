#include <iostream>
void run298() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30778.root";
TString outputFileName = "output298.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
