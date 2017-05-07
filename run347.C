#include <iostream>
void run347() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30903.root";
TString outputFileName = "output347.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
