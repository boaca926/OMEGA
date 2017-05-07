#include <iostream>
void run349() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30906.root";
TString outputFileName = "output349.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
