#include <iostream>
void run173() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30604.root";
TString outputFileName = "output173.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
