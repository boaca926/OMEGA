#include <iostream>
void run212() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30656.root";
TString outputFileName = "output212.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
