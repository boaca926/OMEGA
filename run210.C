#include <iostream>
void run210() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30654.root";
TString outputFileName = "output210.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
