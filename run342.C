#include <iostream>
void run342() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30898.root";
TString outputFileName = "output342.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
