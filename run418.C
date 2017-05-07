#include <iostream>
void run418() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30990.root";
TString outputFileName = "output418.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
