#include <iostream>
void run344() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30900.root";
TString outputFileName = "output344.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
