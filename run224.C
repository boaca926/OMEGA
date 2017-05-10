#include <iostream>
void run224() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30671.root";
TString outputFileName = "output224.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
