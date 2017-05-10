#include <iostream>
void run245() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30705.root";
TString outputFileName = "output245.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
