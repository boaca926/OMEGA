#include <iostream>
void run391() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30953.root";
TString outputFileName = "output391.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
