#include <iostream>
void run288() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30765.root";
TString outputFileName = "output288.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
