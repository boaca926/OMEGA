#include <iostream>
void run273() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30744.root";
TString outputFileName = "output273.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
