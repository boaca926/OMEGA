#include <iostream>
void run411() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30983.root";
TString outputFileName = "output411.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
