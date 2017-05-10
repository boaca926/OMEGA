#include <iostream>
void run191() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30624.root";
TString outputFileName = "output191.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
