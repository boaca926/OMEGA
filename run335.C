#include <iostream>
void run335() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30888.root";
TString outputFileName = "output335.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
