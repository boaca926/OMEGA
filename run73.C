#include <iostream>
void run73() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30467.root";
TString outputFileName = "output73.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
