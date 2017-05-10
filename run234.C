#include <iostream>
void run234() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30682.root";
TString outputFileName = "output234.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
