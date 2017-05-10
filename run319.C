#include <iostream>
void run319() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30862.root";
TString outputFileName = "output319.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
