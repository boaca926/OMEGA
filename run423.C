#include <iostream>
void run423() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30995.root";
TString outputFileName = "output423.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
