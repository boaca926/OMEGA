#include <iostream>
void run266() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30736.root";
TString outputFileName = "output266.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
