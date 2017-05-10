#include <iostream>
void run276() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30747.root";
TString outputFileName = "output276.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
