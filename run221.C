#include <iostream>
void run221() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30668.root";
TString outputFileName = "output221.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
