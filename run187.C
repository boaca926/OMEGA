#include <iostream>
void run187() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30620.root";
TString outputFileName = "output187.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
