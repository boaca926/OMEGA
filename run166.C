#include <iostream>
void run166() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30597.root";
TString outputFileName = "output166.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
