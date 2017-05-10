#include <iostream>
void run171() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30602.root";
TString outputFileName = "output171.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
