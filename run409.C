#include <iostream>
void run409() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30981.root";
TString outputFileName = "output409.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
