#include <iostream>
void run320() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30863.root";
TString outputFileName = "output320.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
