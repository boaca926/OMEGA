#include <iostream>
void run413() {
TString inputFileName = "/home/bo/Desktop/DATA1/MCEEG/mcallrad30985.root";
TString outputFileName = "output413.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
