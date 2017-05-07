#include <iostream>
void run322() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30865.root";
TString outputFileName = "output322.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
