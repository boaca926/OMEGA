#include <iostream>
void run267() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30738.root";
TString outputFileName = "output267.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
