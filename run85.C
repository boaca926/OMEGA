#include <iostream>
void run85() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30490.root";
TString outputFileName = "output85.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
