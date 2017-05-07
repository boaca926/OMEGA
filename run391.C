#include <iostream>
void run391() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30953.root";
TString outputFileName = "output391.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
