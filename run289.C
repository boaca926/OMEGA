#include <iostream>
void run289() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30766.root";
TString outputFileName = "output289.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
