#include <iostream>
void run316() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30859.root";
TString outputFileName = "output316.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
