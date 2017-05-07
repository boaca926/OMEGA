#include <iostream>
void run130() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30555.root";
TString outputFileName = "output130.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
