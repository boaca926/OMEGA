#include <iostream>
void run411() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30983.root";
TString outputFileName = "output411.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
