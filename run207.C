#include <iostream>
void run207() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30651.root";
TString outputFileName = "output207.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
