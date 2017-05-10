#include <iostream>
void run419() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30991.root";
TString outputFileName = "output419.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
