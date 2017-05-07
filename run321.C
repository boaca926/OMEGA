#include <iostream>
void run321() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30864.root";
TString outputFileName = "output321.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
