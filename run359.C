#include <iostream>
void run359() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30917.root";
TString outputFileName = "output359.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
