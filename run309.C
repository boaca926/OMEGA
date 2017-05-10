#include <iostream>
void run309() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30789.root";
TString outputFileName = "output309.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
