#include <iostream>
void run346() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30902.root";
TString outputFileName = "output346.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
