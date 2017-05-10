#include <iostream>
void run427() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30999.root";
TString outputFileName = "output427.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
