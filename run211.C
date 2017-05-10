#include <iostream>
void run211() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30655.root";
TString outputFileName = "output211.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
