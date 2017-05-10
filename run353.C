#include <iostream>
void run353() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30910.root";
TString outputFileName = "output353.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
