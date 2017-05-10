#include <iostream>
void run214() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30658.root";
TString outputFileName = "output214.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
