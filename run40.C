#include <iostream>
void run40() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30389.root";
TString outputFileName = "output40.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
