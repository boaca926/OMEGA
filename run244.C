#include <iostream>
void run244() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30704.root";
TString outputFileName = "output244.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
