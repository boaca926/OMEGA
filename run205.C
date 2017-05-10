#include <iostream>
void run205() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30648.root";
TString outputFileName = "output205.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
