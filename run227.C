#include <iostream>
void run227() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30675.root";
TString outputFileName = "output227.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
