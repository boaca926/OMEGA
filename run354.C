#include <iostream>
void run354() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30911.root";
TString outputFileName = "output354.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
