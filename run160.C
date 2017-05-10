#include <iostream>
void run160() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30590.root";
TString outputFileName = "output160.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
