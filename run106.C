#include <iostream>
void run106() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30520.root";
TString outputFileName = "output106.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
