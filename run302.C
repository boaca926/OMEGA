#include <iostream>
void run302() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30782.root";
TString outputFileName = "output302.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
