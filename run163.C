#include <iostream>
void run163() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30594.root";
TString outputFileName = "output163.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
