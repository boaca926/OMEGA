#include <iostream>
void run167() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30598.root";
TString outputFileName = "output167.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
