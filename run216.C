#include <iostream>
void run216() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30662.root";
TString outputFileName = "output216.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
