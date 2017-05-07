#include <iostream>
void run277() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30748.root";
TString outputFileName = "output277.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
