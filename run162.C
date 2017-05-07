#include <iostream>
void run162() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30593.root";
TString outputFileName = "output162.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
