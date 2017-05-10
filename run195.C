#include <iostream>
void run195() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30628.root";
TString outputFileName = "output195.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
