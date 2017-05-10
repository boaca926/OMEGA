#include <iostream>
void run238() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30695.root";
TString outputFileName = "output238.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
