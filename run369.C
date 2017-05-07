#include <iostream>
void run369() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30928.root";
TString outputFileName = "output369.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
