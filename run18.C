#include <iostream>
void run18() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30346.root";
TString outputFileName = "output18.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
