#include <iostream>
void run337() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30890.root";
TString outputFileName = "output337.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
