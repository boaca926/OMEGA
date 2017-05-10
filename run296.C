#include <iostream>
void run296() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30776.root";
TString outputFileName = "output296.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
