#include <iostream>
void run371() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30930.root";
TString outputFileName = "output371.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
