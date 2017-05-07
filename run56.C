#include <iostream>
void run56() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30437.root";
TString outputFileName = "output56.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
