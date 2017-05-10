#include <iostream>
void run199() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30634.root";
TString outputFileName = "output199.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
