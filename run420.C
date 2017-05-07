#include <iostream>
void run420() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30992.root";
TString outputFileName = "output420.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
