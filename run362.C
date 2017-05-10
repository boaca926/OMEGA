#include <iostream>
void run362() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30921.root";
TString outputFileName = "output362.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
