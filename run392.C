#include <iostream>
void run392() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30954.root";
TString outputFileName = "output392.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
