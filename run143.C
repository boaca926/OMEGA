#include <iostream>
void run143() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30570.root";
TString outputFileName = "output143.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
