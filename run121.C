#include <iostream>
void run121() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30546.root";
TString outputFileName = "output121.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
