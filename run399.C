#include <iostream>
void run399() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30970.root";
TString outputFileName = "output399.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
