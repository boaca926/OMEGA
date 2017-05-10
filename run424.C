#include <iostream>
void run424() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30996.root";
TString outputFileName = "output424.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
