#include <iostream>
void run393() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30955.root";
TString outputFileName = "output393.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
