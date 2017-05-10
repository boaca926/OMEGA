#include <iostream>
void run374() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30933.root";
TString outputFileName = "output374.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
