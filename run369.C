#include <iostream>
void run369() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30928.root";
TString outputFileName = "output369.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
