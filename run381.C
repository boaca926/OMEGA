#include <iostream>
void run381() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30940.root";
TString outputFileName = "output381.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
