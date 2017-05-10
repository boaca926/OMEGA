#include <iostream>
void run252() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30716.root";
TString outputFileName = "output252.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
