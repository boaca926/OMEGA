#include <iostream>
void run322() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30865.root";
TString outputFileName = "output322.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
