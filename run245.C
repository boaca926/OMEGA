#include <iostream>
void run245() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30705.root";
TString outputFileName = "output245.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
