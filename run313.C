#include <iostream>
void run313() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30856.root";
TString outputFileName = "output313.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
