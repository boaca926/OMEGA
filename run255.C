#include <iostream>
void run255() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30720.root";
TString outputFileName = "output255.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
