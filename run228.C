#include <iostream>
void run228() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30676.root";
TString outputFileName = "output228.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
