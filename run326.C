#include <iostream>
void run326() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30873.root";
TString outputFileName = "output326.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
