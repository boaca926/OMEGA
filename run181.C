#include <iostream>
void run181() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30612.root";
TString outputFileName = "output181.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
