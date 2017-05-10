#include <iostream>
void run414() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30986.root";
TString outputFileName = "output414.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
