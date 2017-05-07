#include <iostream>
void run357() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30915.root";
TString outputFileName = "output357.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
