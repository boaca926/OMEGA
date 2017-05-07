#include <iostream>
void run363() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30922.root";
TString outputFileName = "output363.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
