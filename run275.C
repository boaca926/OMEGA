#include <iostream>
void run275() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30746.root";
TString outputFileName = "output275.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
