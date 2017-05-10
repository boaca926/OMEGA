#include <iostream>
void run182() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30613.root";
TString outputFileName = "output182.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
