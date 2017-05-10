#include <iostream>
void run349() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30906.root";
TString outputFileName = "output349.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
