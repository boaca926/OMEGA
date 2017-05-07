#include <iostream>
void run272() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30743.root";
TString outputFileName = "output272.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
