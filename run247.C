#include <iostream>
void run247() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30708.root";
TString outputFileName = "output247.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
