#include <iostream>
void run390() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30952.root";
TString outputFileName = "output390.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
