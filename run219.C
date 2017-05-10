#include <iostream>
void run219() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30666.root";
TString outputFileName = "output219.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
