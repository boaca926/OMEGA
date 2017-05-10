#include <iostream>
void run208() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30652.root";
TString outputFileName = "output208.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
