#include <iostream>
void run223() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30670.root";
TString outputFileName = "output223.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
