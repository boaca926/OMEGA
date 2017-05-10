#include <iostream>
void run420() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30992.root";
TString outputFileName = "output420.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
