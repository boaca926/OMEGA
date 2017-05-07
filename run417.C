#include <iostream>
void run417() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30989.root";
TString outputFileName = "output417.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
