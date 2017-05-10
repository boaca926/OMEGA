#include <iostream>
void run227() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30675.root";
TString outputFileName = "output227.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
