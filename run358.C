#include <iostream>
void run358() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30916.root";
TString outputFileName = "output358.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
