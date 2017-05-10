#include <iostream>
void run268() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30739.root";
TString outputFileName = "output268.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
