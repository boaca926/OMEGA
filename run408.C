#include <iostream>
void run408() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30979.root";
TString outputFileName = "output408.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
