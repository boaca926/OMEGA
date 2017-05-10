#include <iostream>
void run239() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30696.root";
TString outputFileName = "output239.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
