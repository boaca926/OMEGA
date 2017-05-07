#include <iostream>
void run109() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30524.root";
TString outputFileName = "output109.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
