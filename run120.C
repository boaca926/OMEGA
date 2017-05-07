#include <iostream>
void run120() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30545.root";
TString outputFileName = "output120.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
