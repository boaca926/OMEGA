#include <iostream>
void run191() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30624.root";
TString outputFileName = "output191.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
