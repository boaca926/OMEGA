#include <iostream>
void run265() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30735.root";
TString outputFileName = "output265.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
