#include <iostream>
void run302() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30782.root";
TString outputFileName = "output302.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
