#include <iostream>
void run394() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30957.root";
TString outputFileName = "output394.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
