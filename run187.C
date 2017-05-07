#include <iostream>
void run187() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30620.root";
TString outputFileName = "output187.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
