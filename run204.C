#include <iostream>
void run204() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30647.root";
TString outputFileName = "output204.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
