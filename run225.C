#include <iostream>
void run225() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30673.root";
TString outputFileName = "output225.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
