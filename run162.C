#include <iostream>
void run162() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30593.root";
TString outputFileName = "output162.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
