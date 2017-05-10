#include <iostream>
void run256() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30721.root";
TString outputFileName = "output256.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
