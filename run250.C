#include <iostream>
void run250() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30711.root";
TString outputFileName = "output250.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
