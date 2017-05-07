#include <iostream>
void run22() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30370.root";
TString outputFileName = "output22.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
