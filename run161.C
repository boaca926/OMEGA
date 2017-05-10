#include <iostream>
void run161() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30592.root";
TString outputFileName = "output161.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
