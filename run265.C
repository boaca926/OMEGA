#include <iostream>
void run265() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30735.root";
TString outputFileName = "output265.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
