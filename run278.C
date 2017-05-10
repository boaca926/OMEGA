#include <iostream>
void run278() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30752.root";
TString outputFileName = "output278.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
