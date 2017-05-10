#include <iostream>
void run313() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30856.root";
TString outputFileName = "output313.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
