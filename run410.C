#include <iostream>
void run410() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30982.root";
TString outputFileName = "output410.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
