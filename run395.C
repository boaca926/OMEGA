#include <iostream>
void run395() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30958.root";
TString outputFileName = "output395.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
