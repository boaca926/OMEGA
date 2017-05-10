#include <iostream>
void run305() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30785.root";
TString outputFileName = "output305.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
