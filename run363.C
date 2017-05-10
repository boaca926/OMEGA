#include <iostream>
void run363() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30922.root";
TString outputFileName = "output363.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
