#include <iostream>
void run385() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30944.root";
TString outputFileName = "output385.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
