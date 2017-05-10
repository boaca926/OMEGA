#include <iostream>
void run168() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30599.root";
TString outputFileName = "output168.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
