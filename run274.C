#include <iostream>
void run274() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30745.root";
TString outputFileName = "output274.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
