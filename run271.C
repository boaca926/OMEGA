#include <iostream>
void run271() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30742.root";
TString outputFileName = "output271.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
