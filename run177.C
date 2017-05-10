#include <iostream>
void run177() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30608.root";
TString outputFileName = "output177.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
