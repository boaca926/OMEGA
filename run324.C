#include <iostream>
void run324() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30871.root";
TString outputFileName = "output324.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
