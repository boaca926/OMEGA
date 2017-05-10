#include <iostream>
void run325() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30872.root";
TString outputFileName = "output325.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
