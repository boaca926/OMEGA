#include <iostream>
void run347() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30903.root";
TString outputFileName = "output347.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
