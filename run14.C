#include <iostream>
void run14() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30342.root";
TString outputFileName = "output14.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
