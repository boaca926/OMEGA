#include <iostream>
void run194() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30627.root";
TString outputFileName = "output194.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
