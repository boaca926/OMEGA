#include <iostream>
void run389() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30949.root";
TString outputFileName = "output389.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
