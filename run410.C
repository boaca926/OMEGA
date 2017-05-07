#include <iostream>
void run410() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30982.root";
TString outputFileName = "output410.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
