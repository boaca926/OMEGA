#include <iostream>
void run189() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30622.root";
TString outputFileName = "output189.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
