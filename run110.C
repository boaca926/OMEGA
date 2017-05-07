#include <iostream>
void run110() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30525.root";
TString outputFileName = "output110.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
