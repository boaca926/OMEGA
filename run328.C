#include <iostream>
void run328() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30877.root";
TString outputFileName = "output328.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
