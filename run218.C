#include <iostream>
void run218() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30664.root";
TString outputFileName = "output218.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
