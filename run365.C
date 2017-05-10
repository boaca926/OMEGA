#include <iostream>
void run365() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30924.root";
TString outputFileName = "output365.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
