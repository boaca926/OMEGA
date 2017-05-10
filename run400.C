#include <iostream>
void run400() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30971.root";
TString outputFileName = "output400.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
