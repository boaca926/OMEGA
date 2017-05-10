#include <iostream>
void run207() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30651.root";
TString outputFileName = "output207.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
