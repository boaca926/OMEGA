#include <iostream>
void run417() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30989.root";
TString outputFileName = "output417.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
