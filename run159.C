#include <iostream>
void run159() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30589.root";
TString outputFileName = "output159.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
