#include <iostream>
void run307() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30787.root";
TString outputFileName = "output307.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
