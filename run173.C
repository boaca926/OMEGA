#include <iostream>
void run173() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30604.root";
TString outputFileName = "output173.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
