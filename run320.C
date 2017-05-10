#include <iostream>
void run320() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30863.root";
TString outputFileName = "output320.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
