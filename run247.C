#include <iostream>
void run247() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30708.root";
TString outputFileName = "output247.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
