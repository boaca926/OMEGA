#include <iostream>
void run70() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30464.root";
TString outputFileName = "output70.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
