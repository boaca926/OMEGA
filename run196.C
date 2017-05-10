#include <iostream>
void run196() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30631.root";
TString outputFileName = "output196.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
