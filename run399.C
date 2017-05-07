#include <iostream>
void run399() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30970.root";
TString outputFileName = "output399.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
