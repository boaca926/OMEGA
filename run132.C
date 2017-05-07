#include <iostream>
void run132() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30557.root";
TString outputFileName = "output132.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
