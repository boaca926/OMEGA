#include <iostream>
void run295() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30775.root";
TString outputFileName = "output295.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
