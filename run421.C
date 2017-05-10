#include <iostream>
void run421() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30993.root";
TString outputFileName = "output421.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
