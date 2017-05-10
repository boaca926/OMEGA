#include <iostream>
void run251() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30712.root";
TString outputFileName = "output251.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
