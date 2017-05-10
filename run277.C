#include <iostream>
void run277() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30748.root";
TString outputFileName = "output277.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
