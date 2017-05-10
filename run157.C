#include <iostream>
void run157() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30587.root";
TString outputFileName = "output157.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
