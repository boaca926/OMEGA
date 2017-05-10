#include <iostream>
void run287() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30762.root";
TString outputFileName = "output287.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
