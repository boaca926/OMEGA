#include <iostream>
void run319() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30862.root";
TString outputFileName = "output319.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
