#include <iostream>
void run189() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30622.root";
TString outputFileName = "output189.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
