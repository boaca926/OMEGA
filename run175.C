#include <iostream>
void run175() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30606.root";
TString outputFileName = "output175.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
