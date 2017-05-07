#include <iostream>
void run116() {
TString inputFileName = "/media/bo/D93C-9538/DATA1/MCKSL/mcksl30540.root";
TString outputFileName = "output116.root";
  gROOT->ProcessLine(".L MyClass.C+");
  gROOT->ProcessLine(".L Analys.C+");
  gROOT->ProcessLine(Analys(inputFileName,outputFileName));
  exit();
}
