#include <iostream>
void run308() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30788.root";
TString outputFileName = "output308.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
