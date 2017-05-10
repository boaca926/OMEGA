#include <iostream>
void run179() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30610.root";
TString outputFileName = "output179.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
