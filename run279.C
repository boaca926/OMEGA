#include <iostream>
void run279() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30753.root";
TString outputFileName = "output279.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
