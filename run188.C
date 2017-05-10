#include <iostream>
void run188() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30621.root";
TString outputFileName = "output188.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
