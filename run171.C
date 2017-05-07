#include <iostream>
void run171() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30602.root";
TString outputFileName = "output171.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
