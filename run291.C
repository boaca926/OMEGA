#include <iostream>
void run291() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30770.root";
TString outputFileName = "output291.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
