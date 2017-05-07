#include <iostream>
void run288() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30765.root";
TString outputFileName = "output288.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
