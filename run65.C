#include <iostream>
void run65() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30457.root";
TString outputFileName = "output65.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
