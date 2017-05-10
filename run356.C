#include <iostream>
void run356() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30913.root";
TString outputFileName = "output356.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
