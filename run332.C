#include <iostream>
void run332() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30885.root";
TString outputFileName = "output332.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
