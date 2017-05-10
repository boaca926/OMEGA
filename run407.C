#include <iostream>
void run407() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30978.root";
TString outputFileName = "output407.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
