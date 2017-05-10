#include <iostream>
void run378() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30937.root";
TString outputFileName = "output378.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
