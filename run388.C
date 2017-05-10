#include <iostream>
void run388() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30948.root";
TString outputFileName = "output388.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
