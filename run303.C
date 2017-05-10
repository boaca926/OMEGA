#include <iostream>
void run303() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30783.root";
TString outputFileName = "output303.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
