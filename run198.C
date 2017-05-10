#include <iostream>
void run198() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30633.root";
TString outputFileName = "output198.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
