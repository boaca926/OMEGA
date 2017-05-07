#include <iostream>
void run296() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30776.root";
TString outputFileName = "output296.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
