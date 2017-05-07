#include <iostream>
void run390() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30952.root";
TString outputFileName = "output390.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
