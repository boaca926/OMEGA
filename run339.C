#include <iostream>
void run339() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30895.root";
TString outputFileName = "output339.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
