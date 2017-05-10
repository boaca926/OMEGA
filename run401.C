#include <iostream>
void run401() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30972.root";
TString outputFileName = "output401.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
