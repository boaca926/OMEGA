#include <iostream>
void run387() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30946.root";
TString outputFileName = "output387.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
